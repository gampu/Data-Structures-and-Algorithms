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

int t, n, res;
bitset< 10000007 > prime;
vector< int > ans;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	prime.set();
	prime[ 0 ] = 0;
	prime[ 1 ] = 0;
	for( int i = 2; i * i <= 1e7; ++i )
	{
		if( prime[ i ] == 1 )
		{
			for( int j = i * i; j <= 1e7; j += i )
			{
				prime[ j ] = 0;
			}
		}
	}
	for( int i = 5; i <= 1e7; ++i )
	{
		if( prime[ i ] == 1 && prime[ i - 2 ] == 1 )
		{
			ans.emplace_back( i );
		}
	}
	cin >> t;
	for( int z = 1; z <= t; ++z )
	{
		cin >> n;
		res = upper_bound( ans.begin(), ans.end(), n ) - ans.begin();
		cout << res << "\n";
	}
	return 0;
}
