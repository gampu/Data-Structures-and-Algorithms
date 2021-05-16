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

// Order doesn't matter

int t, m, n, val;
vector< int > arr;
vector< vector< int > > dp;

int solve( int n, int m )
{
	if( n < 0 )
	{
		return 0;
	}
	if( m == -1 )
	{
		if( n == 0 )
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if( dp[ n ][ m ] != -1 )
	{
		return dp[ n ][ m ];
	}
	dp[ n ][ m ] = solve( n, m - 1 ) + solve( n - arr[ m ], m );
	return dp[ n ][ m ];
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 0; z <= t - 1; ++z )
	{
		arr.clear();
		cin >> m;
		for( int i = 0; i <= m - 1; ++i )
		{
			cin >> val;
			arr.emplace_back( val );
		}
		cin >> n;
		dp.assign( n + 5, vector< int >( m + 5, -1 ) );
		cout << solve( n, m - 1 ) << "\n";
	}	
	return 0;
}
