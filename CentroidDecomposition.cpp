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

// Centroid Decomposition
// https://codeforces.com/contest/321/problem/C 

int n, u, v;
vector< char > ans( 1e5 + 5 );
vector< int > sub( 1e5 + 5 ), parent( 1e5 + 5 );
vector< set< int > > adj( 1e5 + 5 );

void dfs( int u, int par )
{
	sub[ u ] = 1;
	for( int v : adj[ u ] )
	{
		if( v != par )
		{
			dfs( v, u );
			sub[ u ] += sub[ v ];
		}
	}
}

int centroid( int u, int par, int n )
{
	for( int v : adj[ u ] )
	{
		if( v != par && sub[ v ] > n / 2 )
		{
			return centroid( v, u, n );
		}
	}
	return u;
}

void build( int u, int prev, int level )
{
	dfs( u, -1 );
	int cur = centroid( u, -1, sub[ u ] );
	ans[ cur ] = char( level + 65 );
	if( prev == -1 )
	{
		prev = cur;
	}
	parent[ cur ] = prev;
	for( int v : adj[ cur ] )
	{
		adj[ v ].erase( cur );
		build( v, cur, level + 1 );
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 1; i <= n - 1; ++i )
	{
		cin >> u >> v;
		adj[ u ].insert( v );
		adj[ v ].insert( u );		
	}
	build( 1, -1, 0 );
	for( int i = 1; i <= n; ++i )
	{
		cout << ans[ i ] << " \n"[ i == n ];		
	}
	return 0;
}
