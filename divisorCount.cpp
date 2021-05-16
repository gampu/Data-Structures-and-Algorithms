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

// https://www.spoj.com/problems/NDIV/

const int N = 32000;
int lp[ N + 1 ] = { 0 }, a, b, lim, cnt = 0;
vector< int > pr;

int solve( int n ) // returns number of divisors of n
{
	if( n <= 2 )
	{
		return n;
	}	
	int res, ans = 1;
	for( int i = 0; i <= pr.size() - 1 && pr[ i ] * pr[ i ] <= n; ++i )
	{
		res = 0;
		while( n % pr[ i ] == 0 )
		{
			++res;
			n /= pr[ i ];
		}
		ans *= ( res + 1 );
	}
	if( n != 1 )
	{
		ans *= 2;
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
	cin >> a >> b >> lim;
	for( int i = a; i <= b; ++i )
	{
		if( solve( i ) == lim )
		{
			++cnt;
		}
	}
	cout << cnt << "\n";
	return 0;
}

