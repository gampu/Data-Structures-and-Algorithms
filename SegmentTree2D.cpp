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

/*
	https://cses.fi/problemset/task/1739/
	You are given an n×n grid representing the map of a forest. Each square is either empty or has a tree. Your task is to process q queries of the following types:
	Change the state (empty/tree) of a square.
	How many trees are inside a rectangle in the forest?
*/

const int N = 1003;
int l = ( int )ceil( log2( N ) );
vector< vector< int > > segtree( ( 1 << ( l + 1 ) ) + 10, vector< int >( ( 1 << ( l + 1 ) ) + 10 ) );
vector< vector< int > > arr( N, vector< int >( N ) );
int n, q, type, x, y, a, b, c, d;
char character;

void buildy( int vx, int vy, int tlx, int trx, int tly, int _try )
{
	if( tly == _try )
	{
		if( tlx == trx )
		{
			segtree[ vx ][ vy ] = arr[ tlx ][ tly ];
		}
		else
		{
			segtree[ vx ][ vy ] = segtree[ 2 * vx ][ vy ] + segtree[ 2 * vx + 1 ][ vy ];
		}
	}
	else
	{
		int tm = ( tly + _try ) >> 1;
		buildy( vx, 2 * vy, tlx, trx, tly, tm );
		buildy( vx, 2 * vy + 1, tlx, trx, tm + 1, _try );
		segtree[ vx ][ vy ] = segtree[ vx ][ 2 * vy ] + segtree[ vx ][ 2 * vy + 1 ];
	}
}

void buildx( int vx, int tlx, int trx, int tly, int _try )
{
	if( tlx != trx )
	{
		int tm = ( tlx + trx ) >> 1;
		buildx( 2 * vx, tlx, tm, tly, _try );
		buildx( 2 * vx + 1, tm + 1, trx, tly, _try );
	}
	buildy( vx, 1, tlx, trx, tly, _try );
}

int queryy( int vx, int vy, int tly, int _try, int c, int d )
{
	if( tly == c && _try == d )
	{
		return segtree[ vx ][ vy ];
	}
	int tm = ( tly + _try ) >> 1;
	if( d <= tm )
	{
		return queryy( vx, 2 * vy, tly, tm, c, d );
	}
	else if( c > tm )
	{
		return queryy( vx, 2 * vy + 1, tm + 1, _try, c, d );
	}
	else
	{
		return queryy( vx, 2 * vy, tly, tm, c, tm ) + queryy( vx, 2 * vy + 1, tm + 1, _try, tm + 1, d );
	}
}

int queryx( int vx, int tlx, int trx, int tly, int _try, int a, int b, int c, int d )
{
	if( tlx == a && trx == b )
	{
		return queryy( vx, 1, tly, _try, c, d );
	}
	int tm = ( tlx + trx ) >> 1;
	if( b <= tm )
	{
		return queryx( 2 * vx, tlx, tm, tly, _try, a, b, c, d );
	}
	else if( a > tm )
	{
		return queryx( 2 * vx + 1, tm + 1, trx, tly, _try, a, b, c, d );
	}
	else
	{
		return queryx( 2 * vx, tlx, tm, tly, _try, a, tm, c, d ) + queryx( 2 * vx + 1, tm + 1, trx, tly, _try, tm + 1, b, c, d );
	}
}

void updatey( int vx, int vy, int tlx, int trx, int tly, int _try, int y )
{
	if( tly == _try )
	{
		if( tlx == trx )
		{
			segtree[ vx ][ vy ] = arr[ tlx ][ tly ];
		}
		else
		{
			segtree[ vx ][ vy ] = segtree[ 2 * vx ][ vy ] + segtree[ 2 * vx + 1 ][ vy ];
		}
	}
	else
	{
		int tm = ( tly + _try ) >> 1;
		if( y <= tm )
		{
			updatey( vx, 2 * vy, tlx, trx, tly, tm, y );
		}
		else
		{
			updatey( vx, 2 * vy + 1, tlx, trx, tm + 1, _try, y );
		}
		segtree[ vx ][ vy ] = segtree[ vx ][ 2 * vy ] + segtree[ vx ][ 2 * vy + 1 ];
	}
}

void updatex( int vx, int tlx, int trx, int tly, int _try, int x, int y )
{
	if( tlx != trx )
	{
		int tm = ( tlx + trx ) >> 1;
		if( x <= tm )
		{
			updatex( 2 * vx, tlx, tm, tly, _try, x, y );
		}
		else
		{
			updatex( 2 * vx + 1, tm + 1, trx, tly, _try, x, y );
		}
	}
	updatey( vx, 1, tlx, trx, tly, _try, y );
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> q;
	for( int i = 1; i <= n; ++i )
	{
		for( int j = 1; j <= n; ++j )
		{
			cin >> character;
			( character == '.' ? arr[ i ][ j ] = 0 : arr[ i ][ j ] = 1 );
		}		
	}
	buildx( 1, 1, n, 1, n );
	for( int i = 1; i <= q; ++i )
	{
		cin >> type;
		if( type == 1 )
		{
			cin >> x >> y;
			arr[ x ][ y ] = !arr[ x ][ y ];
			updatex( 1, 1, n, 1, n, x, y );
		}
		else
		{
			cin >> a >> c >> b >> d;
			cout << queryx( 1, 1, n, 1, n, a, b, c, d ) << "\n";
		}
	}		
	return 0;
}
