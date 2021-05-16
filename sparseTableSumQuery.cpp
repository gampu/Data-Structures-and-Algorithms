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

const int MAXN = 1e7;
const int K = 24;
long long int st[ MAXN ][ K + 1 ]; // 25 for MAXN = 1e7
int logTable[ MAXN + 1 ];

long long int sumQuery( int l, int r )
{
	long long int sum = 0;
	for( int j = K; j >= 0; --j )
	{
		if( ( 1 << j ) <= ( r - l + 1 ) )
		{
			sum += st[ l ][ j ];
			l += ( 1 << j );
		}
	}
	return sum;
}

int minQuery( int l, int r )
{
	int z = logTable[ r - l + 1 ];
	return min( st[ l ][ z ], st[ r - ( 1 << z ) + 1 ][ z ] );
}

int main( void )
{
	logTable[ 1 ] = 0;
	for( int i = 2; i <= MAXN; ++i )
	{
		logTable[ i ] = logTable[ i / 2 ] + 1;
	}
	int n, q, type, l, r;
	cin >> n;
	vector< int > data( n );
	for( int i = 0; i <= n - 1; ++i )
	{
		cin >> data[ i ];		
	}
	for( int i = 0; i <= n - 1; ++i )
	{
		st[ i ][ 0 ] = 1LL * data[ i ];		
	}
	for( int j = 1; j <= K; ++j )
	{
		for( int i = 0; i + ( 1 << j ) <= n; ++i )
		{
			st[ i ][ j ] = st[ i ][ j - 1 ] + st[ i + ( 1 << ( j - 1 ) ) ][ j - 1 ];
		}
	}
	cin >> q;
	for( int i = 1; i <= q; ++i )
	{
		cin >> l >> r;
		cout << sumQuery( l, r ) << "\n";
	}
	return 0;
}
