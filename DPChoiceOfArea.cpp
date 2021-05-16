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
#include<tuple>
using namespace std;

int a, b, x, y, res;
map< pair< int, int >, int > dp;
vector< tuple< int, int, int > > arr;
vector< char > ans = { 's' };

int solve( int a, int b, int prev )
{
	if( a <= 0 or b <= 0 )
	{
		return 0;
	}
	if( dp[ { a, b } ] != 0 )
	{
		return dp[ { a, b } ];
	}
	dp[ { a, b } ] = 1;
	for( auto p : arr )
	{
		if( get< 2 >( p ) != prev )
		{
			dp[ { a, b } ] = max( dp[ { a, b } ], 1 + solve( a + get< 0 >( p ), b + get< 1 >( p ), get< 2 >( p ) ) );
		}
	}
	return dp[ { a, b } ];
}

void print( int a, int b, int prev )
{
	if( a <= 0 || b <= 0 )
	{
		if( ans.size() == res + 1 )
		{
			for( int i = 0; i <= ( int )ans.size() - 2; ++i )//for distinct answers, put the relevant part of ans in a set as a vec
			{
				cout << ( char )ans[ i ] << " ";
			}
			cout << "\n";
		}
		return;
	}
	char c = 'x';
	for( auto p : arr )
	{
		if( get< 2 >( p ) != prev && dp[ { a, b } ] == 1 + solve( a + get< 0 >( p ), b + get< 1 >( p ), get< 2 >( p ) ) )
		{
			ans.emplace_back( c );
			print( a + get< 0 >( p ), b + get< 1 >( p ), get< 2 >( p ) );
			ans.pop_back();
		}
		++c;
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> a >> b;
	for( int i = 0; i <= 2; ++i )
	{
		cin >> x >> y;
		arr.push_back( make_tuple( x, y, i ) );
	}
	res = solve( a, b, -1 );
	cout << "\n" << res - 1 << "\n";
	print( a, b, -1 );
	return 0;
}
/*
20 8
3 2
-5 -10
-20 5
*/
