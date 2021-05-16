#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<utility>
#include<functional>
#include<bitset>
#include<cstring>
using namespace std;

//Mo's Algorithm O( ( n * sqrt( n ) + n ) / 2 ) + O( q * sqrt( n ) )

struct node
{
	int l;
	int r;
	int k;
};
typedef struct node Node;

int s, answer = 0;
const int N = 1e6 + 5;
int data[ 30005 ] = { 0 };
int cnt[ N ] = { 0 };
int ans[ N ] = { 0 };

void add( int index )
{
	++cnt[ data[ index ] ];
	if( cnt[ data[ index ] ] == 1 )
	{
		++answer;
	}
}

void remove( int index )
{
	--cnt[ data[ index ] ];
	if( cnt[ data[ index ] ] == 0 )
	{
		--answer;
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

	int n, q, a, b, l, r, k;
	cin >> n;
	s = ( int )ceil( sqrt( n ) );
	for( int i = 0; i <= n - 1; ++i )
	{
		cin >> data[ i ];
	}
	cin >> q;
	vector< Node > queries( q );
	for( int i = 0; i <= q - 1; ++i )
	{
		cin >> a >> b;
		--a, --b;
		queries[ i ] = { a, b, i };
	}
	sort( queries.begin(), queries.end(), comp );
	a = b = 0;
	add( a );
	for( int i = 0; i <= q - 1; ++i )
	{
		l = queries[ i ].l;
		r = queries[ i ].r;
		k = queries[ i ].k;
		while( a < l ) // These 4 whiles' are not at all easy to do in code. See notes for proper explanation.
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
/*
5
1 2 3 4 5
5
1 5
2 4
3 3 
3 5
5 5

5
3
1
3
1
*/
