#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<utility>
#include<functional>
#include<bitset>
#include<cstring>
using namespace std;

int n;
vector< string > names( 100 + 10 );
vector< vector< int > > adj( 26 );
vector< int > num( 26, 0 ), TSNum( 26, 0 ), ans;

void solve( int i, int j )
{
	string s1 = names[ i ], s2 = names[ j ];
	int a = s1.length(), b = s2.length();
	int x = 0, y = 0;
	while( x <= a - 1 and y <= b - 1 and s1[ x ] == s2[ y ] )
	{
		++x;
		++y;
	}
	if( x <= a - 1 and y <= b - 1 )
	{
		adj[ s2[ y ] - 97 ].emplace_back( s1[ x ] - 97 );
	}
	else if( a > b )
	{
		cout << "Impossible" << endl;
		exit( EXIT_SUCCESS );
	}
}

void topoSort( int u )
{
	num[ u ] = 1;
	for( int v : adj[ u ] )
	{
		if( num[ v ] == 0 )
		{
			topoSort( v );
		}
		else if( TSNum[ v ] == 0 )
		{
			cout << "Impossible" << endl;
			exit( EXIT_SUCCESS );
		}
	}
	TSNum[ u ] = 1;
	ans.emplace_back( u );
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 0; i <= n - 1; ++i )
	{
		cin >> names[ i ];		
	}
	for( int i = 0; i <= n - 1; ++i )
	{
		for( int j = i + 1; j <= n - 1; ++j )
		{
			solve( i, j );
		}			
	}
	for( int i = 0; i <= 25; ++i )
	{
		if( num[ i ] == 0 )
		{
			topoSort( i );
		}
	}
	for( int c : ans )
	{
		cout << ( char )( c + 97 );
	}
	cout << endl;
	return 0;
}
// https://codeforces.com/problemset/problem/510/C
