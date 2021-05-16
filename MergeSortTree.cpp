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

// https://www.spoj.com/problems/KQUERY/ 

const int N = 3e4 + 4;
int l = ( int )ceil( log2( N ) );
vector< vector< int > > segtree( ( 1 << ( l + 1 ) ) + 10 );
vector< int > arr( N );
int n, q, a, b, c;

void build( int v, int tl, int tr )
{
	if( tl == tr )
	{
		segtree[ v ].emplace_back( arr[ tl ] );
	}
	else
	{
		int tm = ( tl + tr ) >> 1;
		build( 2 * v, tl, tm );
		build( 2 * v + 1, tm + 1, tr );
		segtree[ v ].resize( segtree[ 2 * v ].size() + segtree[ 2 * v + 1 ].size() );
		merge( segtree[ 2 * v ].begin(), segtree[ 2 * v ].end(), segtree[ 2 * v + 1 ].begin(), segtree[ 2 * v + 1 ].end(),
			   segtree[ v ].begin() );
	}
}

int query( int v, int tl, int tr, int l, int r )
{
	if( tl == l && tr == r )
	{
		return segtree[ v ].size() - ( upper_bound( segtree[ v ].begin(), segtree[ v ].end(), c ) - segtree[ v ].begin() );
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
		return query( 2 * v, tl, tm, l, tm ) + query( 2 * v + 1, tm + 1, tr, tm + 1, r );
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	scanf( "%d", &n );
	for( int i = 1; i <= n; ++i )
	{
		scanf( "%d", &arr[ i ] );
	}
	build( 1, 1, n );
	scanf( "%d", &q );
	for( int i = 1; i <= q; ++i )
	{
		scanf( "%d%d%d", &a, &b, &c );
		printf( "%d\n", query( 1, 1, n, a, b ) );
	}
	return 0;
}
