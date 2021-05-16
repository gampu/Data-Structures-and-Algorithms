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

//Minimum number of coins required to form the sum n using m coins

int t, n, m, val, ans;
vector< int > arr;
vector< vector< int > > dp;

int solve( int n, int m )
{
	if( n < 0 )
	{
		return 1e9;
	}
	if( m == -1 )
	{
		if( n == 0 )
		{
			return 0;
		}
		else
		{
			return 1e9;
		}
	}
	if( dp[ n ][ m ] != -1 )
	{
		return dp[ n ][ m ];
	}
	dp[ n ][ m ] = min( 1 + solve( n - arr[ m ], m ), solve( n, m - 1 ) );
	return dp[ n ][ m ];
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 0; z <= t - 1; ++z )
	{
		cin >> n >> m;
		arr.clear();
		dp.assign( n + 5, vector< int >( m + 5, -1 ) );
		for( int i = 0; i <= m - 1; ++i )
		{
			cin >> val;
			arr.emplace_back( val );
		}
		ans = solve( n, m - 1 );
		if( ans == 1e9 )
		{
			ans = -1;
		}
		cout << ans << "\n";
	}	
	return 0;
}
