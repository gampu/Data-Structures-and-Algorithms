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
using namespace std;

int N = 5001, n;
string s;
long long int ans = 0, p = 31, mod = 1e9 + 9, res;
set< long long int > rbs;
vector< long long int > power( N, 1 ), dp( N, 0 );

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	for( int i = 1; i <= N - 1; ++i )
	{
		power[ i ] = ( power[ i - 1 ] * p ) % mod;
	}
	cin >> s;
	n = s.length();
	for( int i = 1; i <= n; ++i )
	{
		dp[ i ] = ( dp[ i - 1 ] + ( s[ i - 1 ] - 96 ) * power[ i - 1 ] ) % mod;
	}
	for( int l = 1; l <= n; ++l )
	{
		rbs.clear();
		for( int i = 0; i <= n - l; ++i )
		{
			res = ( dp[ i + l ] - dp[ i ] + mod ) % mod;
			res = ( res * power[ n - i - 1 ] ) % mod;
			rbs.insert( res );
		}
		ans += rbs.size();
	}	
	cout << ans << endl;
	return 0;
}
