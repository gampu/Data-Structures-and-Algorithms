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

// Weighted Job Scheduling
// Given n jobs with their benefits, schedule them on a single machine to maximize the total benefit obtained
// https://cses.fi/problemset/task/1140/

struct proj
{
	int s, e, w;
	bool operator< ( const struct proj& other ) const
	{
		if( e < other.e )
		{
			return true;
		}
		if( e == other.e )
		{
			return s < other.s;
		}
		return false;
	}
};
typedef struct proj Proj;

int n, a, b, w;
vector< Proj > arr( 2e5 + 5 );
vector< long long > dp( 2e5 + 5, -1 );

long long solve( int n )
{
	if( n == 0 )
	{
		return 0;
	}
	if( dp[ n ] != -1 )
	{
		return dp[ n ];
	}
	int pos = 0, l = 1, r = n - 1, mid;
	while( l <= r )
	{
		mid = ( l + r ) >> 1;
		if( arr[ mid ].e < arr[ n ].s )
		{
			pos = max( pos, mid );
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	dp[ n ] = max( solve( n - 1 ), arr[ n ].w + solve( pos ) );
	return dp[ n ];
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		cin >> a >> b >> w;
		arr[ i ] = { a, b, w };		
	}
	sort( arr.begin() + 1, arr.begin() + n + 1 );
	cout << solve( n ) << "\n";
	return 0;
}
