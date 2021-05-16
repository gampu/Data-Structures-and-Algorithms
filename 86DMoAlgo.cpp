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

struct node
{
	int l;
	int r;
	int k;
};
typedef struct node Node;

const int N = 1e6 + 6;
int n, q, a, b, l, r, k, s;
long long arr[ N ], ans[ N ], cnt[ N ], answer = 0;
vector< Node > queries;

void add( int index )
{
	answer += arr[ index ] * ( 1LL + 2 * cnt[ arr[ index ] ] );
	++cnt[ arr[ index ] ];
}

void remove( int index )
{
	answer += arr[ index ] * ( 1LL - 2 * cnt[ arr[ index ] ] );
	--cnt[ arr[ index ] ];
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
		if( b1 & 1 )
		{
			return a.r > b.r;
		}
		else
		{
			return a.r < b.r;
		}
	}
	return false;
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );

	cin >> n >> q;
	s = ( int )ceil( sqrt( n ) );
	for( int i = 0; i <= n - 1; ++i )
	{
		cin >> arr[ i ];
	}
	for( int i = 0; i <= q - 1; ++i )
	{
		cin >> a >> b;
		--a, --b;
		queries.push_back( { a, b, i } );
	}
	sort( queries.begin(), queries.end(), comp );
	a = b = 0;
	add( a );
	for( int i = 0; i <= q - 1; ++i )
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
		ans[ k ] = answer;
	}
	for( int i = 0; i <= q - 1; ++i )
	{
		cout << ans[ i ] << "\n";
	}
	return 0;
}
