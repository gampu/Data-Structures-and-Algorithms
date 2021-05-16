#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<iterator>
#include<stack>
#include<queue>
#include<utility>
#include<functional>
#include<bitset>
#include<numeric>
#include<cstring>
using namespace std;

int t, n, w;
vector< int > value( 110 ), weight( 110 ), ans;
int dp[ 110 ][ 110 ];

int solve( int w, int n )
{
	if( w < 0 )
	{
		return -1e9;
	}
	if( n == -1 )
	{
		return 0;
	}
	if( dp[ w ][ n ] != -1 )
	{
		return dp[ w ][ n ];
	}
	dp[ w ][ n ] = max( value[ n ] + solve( w - weight[ n ], n - 1 ), solve( w, n - 1 ) );
	return dp[ w ][ n ];
}

void print( int w, int n )
{
	if( w < 0 )
	{
		return;
	}
	if( n == -1 )
	{
		for( int c : ans )
		{
			cout << c << " ";
		}
		cout << "\n";
		return;
	}
	if( solve( w, n ) == solve( w, n - 1 ) )
	{
		print( w, n - 1 );
	}
	if( solve( w, n ) == value[ n ] + solve( w - weight[ n ], n - 1 ) )
	{
		ans.emplace_back( weight[ n ] );
		print( w - weight[ n ], n - 1 );
		ans.pop_back();
	}
}
		
int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 0; z <= t - 1; ++z )
	{
		memset( dp, -1, sizeof( dp ) );	
		cin >> n >> w;
		for( int i = 0; i <= n - 1; ++i )
		{
			cin >> value[ i ];
		}
		for( int i = 0; i <= n - 1; ++i )
		{
			cin >> weight[ i ];		
		}
		cout << "Solution is: " << "\n";
		cout << solve( w, n - 1 ) << "\n";
		print( w, n - 1 );
	}
	return 0;
}
