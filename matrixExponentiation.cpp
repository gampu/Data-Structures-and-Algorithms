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
typedef vector< vector< long long > > Matrix;

Matrix c = { { 3, 1 }, { 1, 3 } };
long long n, mod = 1e9 + 7;

Matrix mul( Matrix& x, Matrix& y )
{
	Matrix res = { { 0, 0 }, { 0, 0 } };
	for( int i = 0; i <= 1; ++i )
	{
		for( int j = 0; j <= 1; ++j )
		{
			for( int k = 0; k <= 1; ++k )
			{
				res[ i ][ j ] += x[ i ][ k ] * y[ k ][ j ]; 
				res[ i ][ j ] %= mod;
			}
		}
	}
	return res;
}

Matrix binpow( long long n )
{
	if( n == 0 )
	{
		return { { 1, 0 }, { 0, 1 } };
	}
	if( n & 1 )
	{
		Matrix b = binpow( n - 1 );
		return mul( b, c );
	}
	else
	{
		Matrix b = binpow( n / 2 );
		return mul( b, b );
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );

	cin >> n;
	Matrix ans = binpow( n );
	cout << ans[ 0 ][ 0 ] << "\n";
	return 0;
}
