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

// Tarjan's Algorithm for finding LCA

int N = 1e5 + 5, n, a, b, q;
vector< vector< int > > adj( N );
vector< vector< pair< int, int > > > queries( N );
vector< int > visited( N, 0 ), ans( N, 0 ), parent( N, -1 ), size( N, 0 ), ancestor( N, 0 );

void make_set( int v )
{
	ancestor[ v ] = v;
	parent[ v ] = v;
	size[ v ] = 1;
}

int find_set( int v )
{
	if( parent[ v ] == v )
	{
		return v;
	}
	return parent[ v ] = find_set( parent[ v ] );
}

bool unite_set( int a, int b )
{
	a = find_set( a );
	b = find_set( b );
	if( a != b )
	{
		if( size[ a ] < size[ b ] )
		{
			swap( a, b );
		}
		parent[ b ] = a;
		size[ a ] += size[ b ];
		size[ b ] = -1;
	}
}

void dfs( int v, int par )
{
	visited[ v ] = 1;
	make_set( v );
	for( int u : adj[ v ] )
	{
		if( u != par )
		{
			dfs( u, v );
			unite_set( u, v );
			ancestor[ find_set( v ) ] = v;
		}
	}
	for( auto node : queries[ v ] )
	{
		int u = node.first;
		int pos = node.second;
		if( visited[ u ] )
		{
			ans[ pos ] = ancestor[ find_set( u ) ];
		}
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 1; i <= n - 1; ++i )
	{
		cin >> a >> b; // 1 - indexed
		adj[ a ].emplace_back( b );
		adj[ b ].emplace_back( a );
	}
	cin >> q;
	for( int i = 1; i <= q; ++i )
	{
		cin >> a >> b; // 1 - indexed
		queries[ a ].emplace_back( b, i );
		queries[ b ].emplace_back( a, i );
	}
	dfs( 1, -1 );
	for( int i = 1; i <= q; ++i )
	{
		cout << ans[ i ] << "\n";		
	}
	return 0;
}
