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

// https://www.spoj.com/problems/KGSS/

struct node
{
	int one;
	int two;
};
typedef struct node Node;

const int N = 1e5 + 5;
int l = ( int )ceil( log2( N ) );
vector< Node > segtree( ( 1 << ( l + 1 ) ) + 10 );
vector< int > arr( 1e5 + 5 );
int n, q, pos, val, x, y;
char type;

Node combine( Node a, Node b )
{
	Node node;
	vector< int > local = { a.one, a.two, b.one, b.two };
	sort( local.begin(), local.end(), greater< int >() );
	node.one = local[ 0 ];
	node.two = local[ 1 ];
	return node;
}

void build( int v, int tl, int tr )
{
	if( tl == tr )
	{
		segtree[ v ] = { arr[ tl ], -1 };
	}
	else
	{
		int tm = ( tl + tr ) >> 1;
		build( 2 * v, tl, tm );
		build( 2 * v + 1, tm + 1, tr );
		segtree[ v ] = combine( segtree[ 2 * v ], segtree[ 2 * v + 1 ] );
	}
}

Node query( int v, int tl, int tr, int l, int r )
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
		return combine( query( 2 * v, tl, tm, l, tm ), query( 2 * v + 1, tm + 1, tr, tm + 1, r ) );
	}
}

void update( int v, int tl, int tr, int pos, int val )
{
	if( tl == tr )
	{
		segtree[ v ] = { val, -1 };
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
	segtree[ v ] = combine( segtree[ 2 * v ], segtree[ 2 * v + 1 ] );
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		cin >> arr[ i ];		
	}
	build( 1, 1, n );
	cin >> q;
	for( int i = 1; i <= q; ++i )
	{
		cin >> type;
		if( type == 'U' )
		{
			cin >> pos >> val;	
			update( 1, 1, n, pos, val );
		}
		else
		{
			cin >> x >> y;
			Node node = query( 1, 1, n, x, y );
			cout << node.one + node.two << "\n";
		}
	}
	return 0;
}
