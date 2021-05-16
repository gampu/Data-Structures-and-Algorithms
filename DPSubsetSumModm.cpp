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

int n, m;
vector< int > arr( 1e6 + 6 );
int dp[ 1005 ][ 1005 ];

int solve( int sum, int n, int cnt )
{
	if( n == -1 )
	{
		if( sum == 0 && cnt > 0 )
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if( dp[ sum ][ n ] != -1 )
	{
		if( sum == 0 and cnt > 0 )
		{
			dp[ sum ][ n ] = 1;
		}
		//cout << "(" << sum << "," << n << "," << cnt << "):" << dp[ sum ][ n ] << "\n"; Output recursion tree's states
		return dp[ sum ][ n ];
	}
	dp[ sum ][ n ] = max( solve( ( sum + arr[ n ] ) % m, n - 1, cnt + 1 ), solve( sum % m, n - 1, cnt ) );
	//cout << "(" << sum << "," << n << "," << cnt << "):" << dp[ sum ][ n ] << "\n"; // Output recursion tree's states
	return dp[ sum ][ n ];
}


int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> m;
	if( n >= m )
	{
		cout << "YES" << "\n";
		return 0;
	}
	memset( dp, -1, sizeof( dp ) );
	for( int i = 0; i <= n - 1; ++i )
	{
		cin >> arr[ i ];
	}
	if( solve( 0, n - 1, 0 ) == 1 )
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}
	return 0;
}
