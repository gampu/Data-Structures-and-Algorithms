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

const int N = 2e5 + 5;
int l = ( int )ceil( log2( N ) );
vector< long long int > segtree( ( 1 << ( l + 1 ) ) + 10 ), lazy( ( 1 << ( l + 1 ) ) + 10 );
vector< long long int > arr( N );
int n, m, a, b, add, cnt, val;
string s;

void push( int v )
{
	if( lazy[ v ] != 0 )
	{
		segtree[ 2 * v ] += lazy[ v ];
		segtree[ 2 * v + 1 ] += lazy[ v ];
		lazy[ 2 * v ] += lazy[ v ];
		lazy[ 2 * v + 1 ] += lazy[ v ];
		lazy[ v ] = 0;
	}
}

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

void update( int v, int tl, int tr, int l, int r )
{
	if( tl == l && tr == r )
	{
		segtree[ v ] += add;
		lazy[ v ] += add;
		return;
	}
	push( v );
	int tm = ( tl + tr ) >> 1;
	if( r <= tm )
	{
		update( 2 * v, tl, tm, l, r );
	}
	else if( l > tm )
	{
		update( 2 * v + 1, tm + 1, tr, l, r );
	}
	else
	{
		update( 2 * v, tl, tm, l, tm );
		update( 2 * v + 1, tm + 1, tr, tm + 1, r );
	}
	segtree[ v ] = min( segtree[ 2 * v ], segtree[ 2 * v + 1 ] );
}

long long int query( int v, int tl, int tr, int l, int r )
{
	if( tl == l and tr == r )
	{
		return segtree[ v ];
	}
	push( v );
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
	cin >> m;
	cin.get();
	for( int i = 1; i <= m; ++i )
	{
		cnt = 0;
		getline( cin, s );
		stringstream ss( s );
		while( ss >> val )
		{
			++cnt;
			if( cnt == 1 )
			{
				a = val;
			}
			else if( cnt == 2 )
			{
				b = val;
			}
			else
			{
				add = val;
			}
		}
		++a;
		++b;
		if( cnt == 3 )
		{
			if( a <= b )
			{
				update( 1, 1, n, a, b );
			}
			else
			{
				update( 1, 1, n, a, n );
				update( 1, 1, n, 1, b );
			}
		}
		else
		{	
			if( a <= b )
			{
				cout << query( 1, 1, n, a, b ) << "\n";
			}
			else
			{
				cout << min( query( 1, 1, n, a, n ), query( 1, 1, n, 1, b ) ) << "\n";
			}
		}
	}
	return 0;
}
// https://codeforces.com/problemset/problem/52/C
