#pragma GCC optimize( "Ofast" )

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
 
int n, m, k, a, b, c, d, mod = 1e9 + 7;
long long res;
vector< long long > factorial( 2e5 + 5, 1 ), invfactorial( 2e5 + 5, 1 ), dp( 3e3 + 3, 0 );
vector< pair< int, int > > arr;

long long inv( long long a, long long p )
{
	long long res = 1;
	while( p > 0 )
	{
		if( p & 1 )
		{
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		p >>= 1;
	}
	return res;
}

void precompute( void )
{
	for( int i = 2; i <= 2e5 + 4; ++i )
	{
		factorial[ i ] = ( factorial[ i - 1 ] * i ) % mod;
		invfactorial[ i ] = inv( factorial[ i ], mod - 2 );
	}
}
 
long long nCr( int n, int r )
{	
	long long res = factorial[ n ];
	res = ( res * invfactorial[ r ] ) % mod;
	res = ( res * invfactorial[ n - r ] ) % mod;
	return res;
}
 
int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	precompute();
	cin >> n >> m >> k;
	for( int i = 1; i <= k; ++i )
	{
		cin >> a >> b;
		arr.emplace_back( a, b );		
	}
	sort( arr.begin(), arr.end() );
	arr.emplace_back( n, m );
	for( int i = 0; i <= k; ++i )
	{
		c = arr[ i ].first;
		d = arr[ i ].second;
		dp[ i ] = nCr( c + d - 2, c - 1 );
		res = 0;
		for( int j = 0; j <= i - 1; ++j )
		{
			a = arr[ j ].first;
			b = arr[ j ].second;
			if( a <= c && b <= d )
			{
				res += dp[ j ] * nCr( c - a + d - b, c - a );
				if( res >= mod )
				{
					res %= mod;
				}
			}
		}
		dp[ i ] -= res;
		if( dp[ i ] < 0 )
		{
			dp[ i ] += mod;
		}
	}
	cout << dp[ k ] << "\n";
	return 0;
}
