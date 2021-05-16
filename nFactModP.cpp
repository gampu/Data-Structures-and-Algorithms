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

// n! modulo prime p after removing all factors of p from it

long long int n, p;

long long int factmod( long long int n, long long int p )
{
	long long int res = 1;
	while( n > 1 )
	{
		res = ( res * ( ( n / p ) & 1 ? p - 1 : 1 ) ) % p;
		for( long long int i = 2; i <= n % p; ++i )
		{
			res = ( res * i ) % p;
		}
		n /= p;
	}
	return res;
}

long long int brute( long long int n, long long int p )
{
	long long int res = 1, j;
	for( long long int i = 2; i <= n; ++i )
	{
		j = i;
		while( j % p == 0 )
		{
			j /= p;
		}
		res = ( res * j ) % p;
	}
	return res;
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> p;
	cout << factmod( n, p ) << "\n";
	cout << brute( n, p ) << "\n";
	return 0;
}
