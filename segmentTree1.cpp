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

// Maximal subsegment in an interval [ a, b ]
// https://www.spoj.com/problems/GSS1/ 

struct node
{
	long long sum, pre, suf, ans;
};
typedef struct node Node;

const int N = 51000;
int l = ( int )ceil( log2( N ) );
vector< Node > segtree( ( 1 << ( l + 1 ) ) + 10 );
vector< long long > arr( N );
int n, q, a, b;

Node combine( Node l, Node r )
{
	Node node;
	node.ans = max( { l.ans, r.ans, l.suf + r.pre } );
	node.sum = l.sum + r.sum;
	node.pre = max( l.pre, l.sum + r.pre );
	node.suf = max( r.suf, r.sum + l.suf );
	return node;
}

void build( int v, int tl, int tr )
{
	if( tl == tr )
	{
		segtree[ v ] = { arr[ tl ], arr[ tl ], arr[ tl ], arr[ tl ] };
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
		cin >> a >> b;
		cout << query( 1, 1, n, a, b ).ans << "\n";
	}
	return 0;
}
