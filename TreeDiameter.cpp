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

// https://www.spoj.com/problems/PT07Z/
// Length of diameter of a tree

int N = 1e4 + 4, n, a, b;
vector< int > h( N, 0 );
vector< vector< int > > adj( N );

int dfs( int u, int par )
{
	for( int v : adj[ u ] )
	{
		if( v != par )
		{
			h[ u ] = max( h[ u ], 1 + dfs( v, u ) );
		}
	}
	return h[ u ];
}

int diameter( int u, int par )
{
	int one = -1, two = -1, res = 0;
	for( int v : adj[ u ] )
	{
		if( v != par )
		{
			if( h[ v ] >= one )
			{
				two = one;
				one = h[ v ];
			}
			else if( h[ v ] > two )
			{
				two = h[ v ];
			}
			res = max( res, diameter( v, u ) );
		}
	}
	return max( res, 2 + one + two );
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 1; i <= n - 1; ++i )
	{
		cin >> a >> b;
		adj[ a ].emplace_back( b );
		adj[ b ].emplace_back( a );
	}
	dfs( 1, 0 );
	cout << diameter( 1, 0 ) << "\n";
	return 0;
}
