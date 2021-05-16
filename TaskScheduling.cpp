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

// Task Scheduling Problem on machines
// Algorithm Design and Applications pg. 289

int n, machine, cnt = 0;
set< pair< int, int > > s;
vector< pair< int, int > > arr( 1e5 + 5 );
vector< vector< pair< int, int > > > ans( 1e5 + 5 );

void print( vector< pair< int, int > >& arr )
{
	cout << arr.size() << "\n";
	for( int i = 1; i <= arr.size(); ++i )
	{
		cout << '(' << arr[ i - 1 ].first << ',' << arr[ i - 1 ].second << ')' << " \n"[ i == arr.size() ];
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		cin >> arr[ i ].first >> arr[ i ].second;	
	}
	sort( arr.begin() + 1, arr.begin() + n + 1 );
	for( int i = 1; i <= n; ++i )
	{
		auto it = s.upper_bound( { arr[ i ].first, n + 1 } );
		if( it == s.begin() )
		{
			++cnt;
			machine = cnt;
		}
		else
		{
			--it;
			machine = it->second;
			s.erase( *it );
		}
		s.insert( { arr[ i ].second, machine } );
		ans[ machine ].emplace_back( arr[ i ] );
	}
	cout << cnt << "\n";
	for( int i = 1; i <= cnt; ++i )
	{
		print( ans[ i ] );
	}	
	return 0;
}
