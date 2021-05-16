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

// https://www.spoj.com/problems/DIVSUM/ 

const int N = 710; // sqrt( max of input elements )
int lp[ N + 1 ] = { 0 }, t, n, res;
vector< int > pr;

long long binpow( int a, int n )
{
	if( n == 0 )
	{
		return 1;
	}
	if( n & 1 )
	{
		return binpow( a, n - 1 ) * a;
	}
	else
	{
		long long res = binpow( a, ( n >> 1 ) );
		return res * res;
	}
}

long long solve( int n ) // returns sum of all divisors of n
{
	if( n == 1 )
	{
		return 1;
	}
	long long ans = 1;
	for( int i = 0; i <= pr.size() - 1 && pr[ i ] * pr[ i ] <= n; ++i )
	{
		res = 0;
		while( n % pr[ i ] == 0 )
		{
			++res;
			n /= pr[ i ];
		}
		if( res )
		{
			ans *= ( binpow( pr[ i ], res + 1 ) - 1 ) / ( pr[ i ] - 1 );
		}
	}
	if( n != 1 )
	{
		ans *= ( n + 1 );
	}
	return ans;
}

int main( void )
{
	for( int i = 2; i <= N; ++i )
	{
		if( lp[ i ] == 0 )
		{
			lp[ i ] = i;
			pr.emplace_back( i );
		}
		for( int j = 0; j <= pr.size() - 1 and pr[ j ] <= lp[ i ] and pr[ j ] * i <= N; ++j )
		{
			lp[ pr[ j ] * i ] = pr[ j ];
		}
	}
	cin >> t;
	for( int z = 1; z <= t; ++z )
	{
		cin >> n;
		cout << solve( n ) - n << "\n";
	}
	return 0;
}
