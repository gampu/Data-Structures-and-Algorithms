#pragma GCC optimize( "Ofast" )
#pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native" )
#pragma comment( linker, "/stack:200000000" )

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

struct edge
{
	int s, e, w, id;
	bool operator< ( const struct edge& other )
	{
		return w < other.w;
	}
};
typedef struct edge Edge;

const int N = 2e5 + 5;
long long res = 0;
int n, m, a, b, w, id, l = 21;
vector< Edge > edges;
vector< int > h( N, 0 ), parent( N, -1 ), size( N, 0 ), present( N, 0 );
vector< long long > ans( N );
vector< vector< pair< int, int > > > adj( N );
vector< vector< int > > up( N, vector< int >( l, -1 ) ), dp( N, vector< int >( l, -1 ) );

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
		return true;
	}
	return false;
}

void dfs( int u, int par, int d )
{
	h[ u ] = 1 + h[ par ];
	up[ u ][ 0 ] = par;
	dp[ u ][ 0 ] = d;
	for( auto v : adj[ u ] )
	{
		if( v.first != par )
		{	
			dfs( v.first, u, v.second );
		}
	}
}

int lca( int u, int v )
{
	int ans = -1;
	if( h[ u ] < h[ v ] )
	{
		swap( u, v );
	}
	for( int i = l - 1; i >= 0; --i )
	{
		if( h[ u ] - h[ v ] >= ( 1 << i ) )
		{
			ans = max( ans, dp[ u ][ i ] );
			u = up[ u ][ i ];
		}
	}
	if( u == v )
	{
		return ans;
	}
	for( int i = l - 1; i >= 0; --i )
	{
		if( up[ u ][ i ] != -1 && up[ v ][ i ] != -1 && up[ u ][ i ] != up[ v ][ i ] )
		{
			ans = max( { ans, dp[ u ][ i ], dp[ v ][ i ] } );
			u = up[ u ][ i ];
			v = up[ v ][ i ];
		}
	}
	ans = max( { ans, dp[ u ][ 0 ], dp[ v ][ 0 ] } );
	return ans;
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> m;
	for( int i = 1; i <= n; ++i )
	{
		parent[ i ] = i;
		size[ i ] = 1;
	}
	for( int i = 1; i <= m; ++i )
	{
		cin >> a >> b >> w;
		edges.push_back( { a, b, w, i - 1 } );
	}
	sort( edges.begin(), edges.end() );
	for( int i = 0; i <= m - 1; ++i )
	{
		a = edges[ i ].s;
		b = edges[ i ].e;
		w = edges[ i ].w;
		id = edges[ i ].id;
		if( unite_set( a, b ) )
		{
			adj[ a ].emplace_back( b, w );
			adj[ b ].emplace_back( a, w );
			present[ id ] = 1;
			res += w;
		}
	}
	dfs( 1, 0, 0 );
	for( int i = 1; i <= l - 1; ++i )
	{
		for( int j = 1; j <= n; ++j )
		{
			if( up[ j ][ i - 1 ] != -1 )
			{
				int v = up[ j ][ i - 1 ];
				up[ j ][ i ] = up[ v ][ i - 1 ];
				dp[ j ][ i ] = max( dp[ j ][ i - 1 ], dp[ v ][ i - 1 ] );
			}
		}
	}
	for( int i = 0; i <= m - 1; ++i )
	{
		id = edges[ i ].id;
		if( present[ id ] )
		{
			ans[ id ] = res;
		}
		else
		{
			ans[ id ] = res + edges[ i ].w - lca( edges[ i ].s, edges[ i ].e );
		}
	}
	for( int i = 0; i <= m - 1; ++i )
	{
		cout << ans[ i ] << "\n";
	}
	return 0;
}
