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

// Total number of distinct subsequences of a given string
// https://www.spoj.com/problems/DSUBSEQ/

int t, n, mod = 1e9 + 7, last[ 100 ];
string s;
long long sum;
vector< long long > dp( 1e5 + 5 );

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 1; z <= t; ++z )
	{	
		memset( last, 0, sizeof( last ) );
		sum = 1;
		cin >> s;
		n = s.length();
		for( int i = 1; i <= n; ++i )
		{
			dp[ i ] = sum;
			if( last[ s[ i - 1 ] ] )
			{
				sum -= dp[ last[ s[ i - 1 ] ] ];
				sum += mod;
				sum %= mod;
				dp[ last[ s[ i - 1 ] ] ] = 0;
			}
			last[ s[ i - 1 ] ] = i;
			sum += dp[ i ];
			sum %= mod;
		}
		cout << sum << "\n";
	}	
	return 0;
}
