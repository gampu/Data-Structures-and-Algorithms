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

// Least Common Ancestor Algorithm using Euler Tour Concept

const int N = 1e5 + 5;
int n, a, b, q, k = 1;
int l = ( int )ceil( log2( 2 * N ) );
vector< int > segtree( ( 1 << ( l + 1 ) ) + 10 );
vector< vector< int > > adj( N );
vector< int > euler( 2 * N ), height( N ), firstoccur( N );

void dfs( int u, int par, int h )
{
	euler[ k ] = u;
	height[ u ] = h;
	firstoccur[ u ] = k;
	++k;
	for( int v : adj[ u ] )
	{
		if( v != par )
		{
			dfs( v, u, h + 1 );
			euler[ k ] = u;
			++k;
		}
	}
}

void build( int v, int tl, int tr )
{
	if( tl == tr )
	{
		segtree[ v ] = euler[ tl ];
	}
	else
	{
		int tm = ( tl + tr ) >> 1;
		build( 2 * v, tl, tm );
		build( 2 * v + 1, tm + 1, tr );
		segtree[ v ] = ( height[ segtree[ 2 * v ] ] < height[ segtree[ 2 * v + 1 ] ] ? segtree[ 2 * v ] : segtree[ 2 * v + 1 ] );
	}
}

int query( int v, int tl, int tr, int l, int r )
{
	if( tl == l and tr == r )
	{
		return segtree[ v ];
	}
	int tm = ( tl + tr ) >> 1;
	if( r <= tm )
	{
		return query( 2 * v, tl, tm, l, r );
	}
	else if( l > tm )
	{
		return query( 2 * v + 1, tm + 1, tr, l, r );
	}
	else
	{
		int v1 = query( 2 * v, tl, tm, l, tm );
		int v2 = query( 2 * v + 1, tm + 1, tr, tm + 1, r );
		return ( height[ v1 ] < height[ v2 ] ? v1 : v2 );
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 1; i <= n - 1; ++i )
	{
		cin >> a >> b; // 1-indexed
		adj[ a ].emplace_back( b );
		adj[ b ].emplace_back( a );
	}
	dfs( 1, -1, 1 );
	build( 1, 1, 2 * n - 1 );
	cin >> q;
	for( int i = 1; i <= q; ++i )
	{
		cin >> a >> b;
		a = firstoccur[ a ];
		b = firstoccur[ b ];
		if( a > b )
		{
			swap( a, b );
		}
		cout << query( 1, 1, 2 * n - 1, a, b ) << "\n";
	}
	return 0;
}
// 1. https://www.spoj.com/problems/LCA/
