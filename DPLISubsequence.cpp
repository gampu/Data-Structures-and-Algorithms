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

// Longest Increasing Subsequence with all solutions

ostream_iterator< int > output( cout, " " );
int n, res = 0;
vector< int > arr( 1e3 + 3 ), dp( 1e3 + 3, -1 ), ans;

int solve( int j )
{
	if( j == 0 )
	{
		return 0;
	}
	if( dp[ j ] != -1 )
	{
		return dp[ j ];
	}
	for( int k = j - 1; k >= 0; --k )
	{
		if( arr[ k ] < arr[ j ] )
		{
			dp[ j ] = max( dp[ j ], 1 + solve( k ) );
		}
	}
	return dp[ j ];
}

void print( int j )
{
	if( j == 0 )
	{
		copy( ans.rbegin(), ans.rend(), output );
		cout << "\n";
		return;
	}
	for( int k = j - 1; k >= 0; --k )
	{
		if( arr[ k ] < arr[ j ] && dp[ j ] == 1 + solve( k ) )
		{
			ans.emplace_back( arr[ j ] );
			print( k );
			ans.pop_back();
		}
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	arr[ 0 ] = -1;
	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		cin >> arr[ i ];
		res = max( res, solve( i ) );
	}
	cout << res << "\n";
	for( int i = 1; i <= n; ++i )
	{
		if( dp[ i ] == res )
		{
			print( i );
		}
	}
	return 0;
}
