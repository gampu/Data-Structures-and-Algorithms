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

int t, n, sum, val, res, cnt = 0;
vector< int > arr, ans;
int dp[ 100005 ][ 105 ];

int solve( int s, int n )
{
	if( s < 0 )
	{
		return 0;
	}
	if( n == -1 )
	{
		if( s == 0 )
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if( dp[ s ][ n ] != -1 )
	{
		return dp[ s ][ n ];
	}
	dp[ s ][ n ] = max( solve( s - arr[ n ], n - 1 ), solve( s, n - 1 ) );
	return dp[ s ][ n ];
}

void print( int s, int n )
{
	if( s < 0 )
	{
		return;
	}
	if( n == -1 )
	{
		if( s == 0 )
		{
			for( int c : ans )
			{
				cout << c << " ";
			}
			cout << "\n";
			++cnt;
			return;
		}
		else
		{
			return;
		}
	}
	if( solve( s, n ) == solve( s, n - 1 ) )
	{
		print( s, n - 1 );
	}	
	if( solve( s, n ) == solve( s - arr[ n ], n - 1 ) )
	{
		ans.emplace_back( arr[ n ] );
		print( s - arr[ n ], n - 1 );
		ans.pop_back();
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 0; z <= t - 1; ++z )
	{
		cnt = 0;
		arr.clear();
		ans.clear();
		memset( dp, -1, sizeof( dp ) );
		cin >> n;
		for( int i = 0; i <= n - 1; ++i )
		{
			cin >> val;
			arr.emplace_back( val );
		}
		cin >> sum;
		res = solve( sum, n - 1 );
		if( res == 1 )
		{
			cout << "YES" << "\n";
			cout << "Solution is: " << "\n";
			print( sum, n - 1 );
			cout << "Count: " << cnt << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}	
	return 0;
}
