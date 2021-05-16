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

// Second Best Minimum Spanning Tree

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
long long res = 0, ans = 1e18;
int n, m, a, b, w, id, edgeId = -1, l = 21;
vector< Edge > edges;
vector< int > h( N, 0 ), parent( N, -1 ), size( N, 0 ), present( N, 0 );
vector< vector< pair< int, int > > > adj( N ), dp( N, vector< pair< int, int > >( l ) );
vector< vector< int > > up( N, vector< int >( l, -1 ) );

pair< int, int > combine( pair< int, int > a, pair< int, int > b )
{
	vector< int > arr = { a.first, a.second, b.first, b.second };
	int two = -3, one = -2;
	for( int c : arr )
	{
		if( c > one )
		{
			two = one;
			one = c;
		}
		else if( c > two && c < one )
		{
			two = c;
		}
	}
	return { one, two };
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
		return true;
	}
	return false;
}

void dfs( int u, int par, int d )
{
	h[ u ] = 1 + h[ par ];
	up[ u ][ 0 ] = par;
	dp[ u ][ 0 ] = { d, -1 };
	for( auto v : adj[ u ] )
	{
		if( v.first != par )
		{	
			dfs( v.first, u, v.second );
		}
	}
}

pair< int, int > lca( int u, int v )
{
	pair< int, int > ans = { -2, -3 };
	if( h[ u ] < h[ v ] )
	{
		swap( u, v );
	}
	for( int i = l - 1; i >= 0; --i )
	{
		if( h[ u ] - h[ v ] >= ( 1 << i ) )
		{
			ans = combine( ans, dp[ u ][ i ] );
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
			ans = combine( ans, combine( dp[ u ][ i ], dp[ v ][ i ] ) );
			u = up[ u ][ i ];
			v = up[ v ][ i ];
		}
	}
	ans = combine( ans, combine( dp[ u ][ 0 ], dp[ v ][ 0 ] ) );
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
				dp[ j ][ i ] = combine( dp[ j ][ i - 1 ], dp[ v ][ i - 1 ] );
			}
		}
	}
	for( int i = 0; i <= m - 1; ++i )
	{
		id = edges[ i ].id;
		w = edges[ i ].w;
		if( !present[ id ] )
		{
			auto rem = lca( edges[ i ].s, edges[ i ].e );
			if( rem.first != w )
			{
				if( ans > res + w - rem.first )
				{
					ans = res + w - rem.first;
					edgeId = id;
				}
			}
			else if( rem.second != -1 )
			{
				if( ans > res + w - rem.second )
				{
					ans = res + w - rem.second;
					edgeId = id;
				}
			}
		}
	}
	cout << ans << " " << edgeId << "\n";
	return 0;
}
/*
Example 1:
6 10
1 2 13
1 6 28
1 5 7
2 6 27
2 3 39 
3 6 34
3 4 36
4 6 14
4 5 7
5 6 2

65 6 
// 65 is the sum of the weights of edges in the second best MST;
// 6 is the 0-based id of the new edge to be included to obtain the second best MST.
// Code can be appropriately modified to remember the id of the edge to be removed from the first best MST.
*/

