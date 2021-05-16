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
using int64 = uint64_t;
using int128 = __uint128_t;

// Prime or Not
// Not working at the moment( as of 04/05/2019 )

int t;
int64 n;

int128 binpow( int a, int64 d, int64 n )
{
	int128 res = 1;
	while( d > 0 )
	{
		if( d & 1 )
		{
			res *= a;
			res %= n;
		}
		a *= a;
		a %= n;
		d >>= 1;
	}
	return res;
}

bool check_composite( int64 n, int64 d, int s, int a )
{
	int128 res = binpow( a, d, n );
	if( res == 1 || res == n - 1 )
	{
		return false;
	}
	for( int i = 1; i <= s - 1; ++i )
	{
		res *= res;
		res %= n;
		if( res == n - 1 )
		{
			return false;
		}
	}
	return true;
}

bool MillerRabin( int64 n )
{
	if( n == 1 )
	{
		return false;
	}
	int64 d = n - 1;
	int s = 0;
	while( !( d & 1 ) )
	{
		++s;
		d >>= 1;
	}
	for( int a : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 } )
	{
		if( n == a )
		{
			return true;
		}
		if( check_composite( n, d, s, a ) )
		{
			return false;
		}
	}
	return true;
}

int main( void )
{ 
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 1; z <= t; ++z )
	{
		cin >> n;
		if( MillerRabin( n ) )
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}
	return 0;
}
