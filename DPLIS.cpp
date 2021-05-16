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

// Longest Strictly Increasing Subsequence Length and Solution in O( nlogn )

int n, j, pos = 0, ind;
vector< int > arr( 1e3 + 5 ), dp1( 1e3 + 5, 1e9 ), dp2( 1e3 + 3, 0 ), parent( 1e3 + 5 ), ans;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
		
	dp1[ 0 ] = -1e9;
	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		cin >> arr[ i ];		
	}
	for( int i = 1; i <= n; ++i )
	{
		j = upper_bound( dp1.begin(), dp1.begin() + n + 1, arr[ i ] ) - dp1.begin();
		if( j != n + 1 && dp1[ j - 1 ] < arr[ i ] )
		{
			dp1[ j ] = arr[ i ];
			pos = max( pos, j );
			dp2[ j ] = i;
			parent[ i ] = dp2[ j - 1 ];
		}		
	}
	cout << pos << "\n"; // LIS length
	ind = dp2[ pos ];	 // Optimal Solution
	while( ind != 0 )
	{
		ans.emplace_back( arr[ ind ] );
		ind = parent[ ind ];
	}
	reverse( ans.begin(), ans.end() );
	for( int i = 0; i <= pos - 1; ++i )
	{
		cout << ans[ i ] << " \n"[ i == pos - 1 ];
	}
	return 0;
}
