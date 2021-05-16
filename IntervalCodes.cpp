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

// Merge Overlapping Intervals
// https://practice.geeksforgeeks.org/problems/overlapping-intervals/0

int t, n, j, l, r;
vector< pair< int, int > > arr, ans;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 1; z <= t; ++z )
	{
		arr.clear();
		ans.clear();
		j = 0;
		cin >> n;
		for( int i = 1; i <= n; ++i )
		{
			cin >> l >> r;
			arr.emplace_back( l, r );		
		}
		sort( arr.begin(), arr.end() );
		ans.push_back( arr[ 0 ] );
		for( int i = 1; i <= n - 1; ++i )
		{
			l = max( ans[ j ].first, arr[ i ].first );
			r = min( ans[ j ].second, arr[ i ].second );
			if( r - l + 1 > 0 )
			{
				ans[ j ].first = min( ans[ j ].first, arr[ i ].first );
				ans[ j ].second = max( ans[ j ].second, arr[ i ].second );
			}
			else
			{
				++j;
				ans.push_back( arr[ i ] );
			}
		}
		for( auto interval : ans )
		{
			cout << interval.first << " " << interval.second << " ";
		}
		cout << "\n";
	}
	return 0;
}
