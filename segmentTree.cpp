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

const int N = 2e5 + 5;
int l = ( int )ceil( log2( N ) );
vector< int > segtree( ( 1 << ( l + 1 ) ) + 10 );
vector< int > arr( N );
int n, q, a, b;

void build( int v, int tl, int tr )
{
	if( tl == tr )
	{
		segtree[ v ] = arr[ tl ];
	}
	else
	{
		int tm = ( tl + tr ) >> 1;
		build( 2 * v, tl, tm );
		build( 2 * v + 1, tm + 1, tr );
		segtree[ v ] = min( segtree[ 2 * v ], segtree[ 2 * v + 1 ] );
	}
}

int query( int v, int tl, int tr, int l, int r )
{
	if( tl == l && tr == r )
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
		return min( query( 2 * v, tl, tm, l, tm ), query( 2 * v + 1, tm + 1, tr, tm + 1, r ) );
	}
}

void update( int v, int tl, int tr, int pos, int val )
{
	if( tl == tr )
	{
		segtree[ v ] = val;
		return;
	}
	int tm = ( tl + tr ) >> 1;
	if( pos <= tm )
	{
		update( 2 * v, tl, tm, pos, val );
	}
	else
	{
		update( 2 * v + 1, tm + 1, tr, pos, val );
	}
	segtree[ v ] = min( segtree[ 2 * v ], segtree[ 2 * v + 1 ] );
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> q;
	for( int i = 1; i <= n; ++i )
	{
		cin >> arr[ i ];
	}
	build( 1, 1, n );
	for( int i = 1; i <= q; ++i )
	{
		cin >> a >> b;
		cout << query( 1, 1, n, a, b ) << "\n";
	}
	return 0;
}
