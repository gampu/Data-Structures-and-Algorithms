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
#include<unordered_map>
using namespace std;

struct node
{
	int l;
	int r;
	int k;
};
typedef struct node Node;

const int N = 1e6 + 6;
int n, q, a, b, l, r, k, s, answer = 0;
int arr[ N ], ans[ N ], dp[ N ] = { 0 };
unordered_map< int, int > m;
vector< Node > queries( N );

void add( int index )
{
	++m[ arr[ index ] ];
	if( m[ arr[ index ] ] == 1 )
	{
		answer ^= arr[ index ];
	}
}

void remove( int index )
{
	--m[ arr[ index ] ];
	if( m[ arr[ index ] ] == 0 )
	{
		answer ^= arr[ index ];
	}
}

bool comp( Node& a, Node& b )
{
	int b1 = a.l / s, b2 = b.l / s;
	if( b1 < b2 )
	{
		return true;
	}
	else if( b1 == b2 )
	{
		return a.r < b.r;
	}
	return false;
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );

	cin >> n;
	s = int( log( n ) ) + 1;
	for( int i = 1; i <= n; ++i )
	{
		cin >> arr[ i ];
	}
	for( int i = 1; i <= n; ++i )
	{
		dp[ i ] = dp[ i - 1 ] ^ arr[ i ];		
	}
	cin >> q;
	for( int i = 1; i <= q; ++i )
	{
		cin >> a >> b;
		queries[ i ] = { a, b, i };
	}
	sort( queries.begin() + 1, queries.begin() + q + 1, comp );
	a = b = 1;
	add( a );
	for( int i = 1; i <= q; ++i )
	{
		l = queries[ i ].l;
		r = queries[ i ].r;
		k = queries[ i ].k;
		while( a < l )
		{
			remove( a );
			++a;
		}
		while( a > l )
		{
			add( a - 1 );
			--a;
		}
		while( b > r )
		{
			remove( b );
			--b;
		}
		while( b < r )
		{
			add( b + 1 );
			++b;
		}
		ans[ k ] = answer ^ dp[ r ] ^ dp[ l - 1 ];
	}
	for( int i = 1; i <= q; ++i )
	{
		cout << ans[ i ] << "\n";
	}
	return 0;
}
