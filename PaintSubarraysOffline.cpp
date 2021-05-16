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

// Paint Subarrays Offline 1 <= l <= r <= n; c >= 1

struct node
{
	int l;
	int r;
	int color;
};
typedef struct node Node;

const int N = 2e5 + 5;
int n, q, l, r, c, a, b, cnt, head, j;
vector< Node > queries( N );
vector< int > ans( N, 0 ), dsupar( N ), parent( N );

int find_set( int v )
{
	if( dsupar[ v ] == v )
	{
		return v;
	}
	return dsupar[ v ] = find_set( parent[ dsupar[ v ] ] );
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> q;
	for( int i = 1; i <= q; ++i )
	{
		cin >> l >> r >> c;
		queries[ i ] = { l, r, c };	
	}
	for( int i = 1; i <= n + 1; ++i )
	{
		dsupar[ i ] = parent[ i ] = i;
	}
	for( int i = q; i >= 1; --i )
	{
		a = queries[ i ].l;
		b = queries[ i ].r;
		c = queries[ i ].color;
		cnt = 0;
		for( head = j = find_set( parent[ a ] ); j <= b; j = find_set( parent[ j + 1 ] ) )
		{
			++cnt;
			ans[ j ] = c;
			parent[ j ] = head;
		}
		if( cnt )
		{
			dsupar[ head ] = j;
		}
	}
	for( int i = 1; i <= n; ++i )
	{
		cout << ans[ i ] << "\n";
	}
	return 0;
}
