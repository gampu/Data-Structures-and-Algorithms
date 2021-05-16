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

// Bitmasking with DP
// Count the total number of ways of assigning unique caps to a set of n people from their collections

int n, m, cap;
vector< vector< int > > arr( 101 );
long long dp[ 100005 ][ 105 ];

long long solve( int status, int i )
{
	if( i == 0 )
	{
		if( status == ( 1 << n ) - 1 )
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if( dp[ status ][ i ] != -1 )
	{
		return dp[ status ][ i ];
	}
	dp[ status ][ i ] = solve( status, i - 1 );
	for( int j = 0; j <= ( int )arr[ i ].size() - 1; ++j )
	{
		int p = arr[ i ][ j ];
		if( ( status & ( 1 << p ) ) == 0 )
		{
			dp[ status ][ i ] += solve( status | ( 1 << p ), i - 1 );
		}
	}
	return dp[ status ][ i ];p
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	memset( dp, -1, sizeof( dp ) );
	cin >> n;
	for( int i = 0; i <= n - 1; ++i )
	{
		cin >> m;
		for( int j = 1; j <= m; ++j )
		{
			cin >> cap;
			arr[ cap ].emplace_back( i );
		}
	}
	cout << solve( 0, 100 ) << "\n";		
	return 0;
}
