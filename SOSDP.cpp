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

// Sum over Subsets DP
// Given an array of 2 ^ n integers, we need to calculate function F(x) = ∑ Ai such that x & i == i for all x. i.e, i is a bitwise
// subset of x. i will be a bitwise subset of mask x, if x & i == i.
// O( ( 2 ^ n ) * n )

int n, val, ans;
vector< int > arr;
long long dp[ 1030 ][ 11 ];

long long solve( int status, int i )
{
	if( i == -1 )
	{
		return arr[ status ];
	}
	if( dp[ status ][ i ] != -1 )
	{
		return dp[ status ][ i ];
	}
	dp[ status ][ i ] = 0;
	dp[ status ][ i ] += solve( ( status & ~( 1 << i ) ), i - 1 );
	if( ( status & ( 1 << i ) ) != 0 )
	{
		dp[ status ][ i ] += solve( status, i - 1 );
	}
	return dp[ status ][ i ];
}
	
int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	memset( dp, -1, sizeof( dp ) );
	cin >> n;
	for( int i = 1; i <= ( 1 << n ); ++i )
	{
		cin >> val;
		arr.emplace_back( val );		
	}
	for( int i = 0; i <= ( 1 << n ) - 1; ++i )
	{
		cout << solve( i, n - 1 ) << " ";
		ans = arr[ 0 ];
		for( int s = i; s > 0; s = ( s - 1 ) & i )
		{
			ans += arr[ s ];
		}
		cout << ans << "\n";
	}
	return 0;
}
