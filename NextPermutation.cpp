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

int t, n;
vector< int > arr( 1e6 + 6 );

void solve( void )
{
	int i, j;
	for( i = n - 1; i >= 1; --i )
	{
		if( arr[ i ] < arr[ i + 1 ] )
		{
			break;
		}
	}
	if( i == 0 )
	{
		cout << -1;
		return;
	}
	for( j = n; j >= i + 1; --j )
	{
		if( arr[ j ] > arr[ i ] )
		{
			break;
		}
	}
	swap( arr[ i ], arr[ j ] );
	reverse( arr.begin() + i + 1, arr.begin() + n + 1 );
	for( int i = 1; i <= n; ++i )
	{
		cout << arr[ i ];
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 1; z <= t; ++z )
	{
		cin >> n;
		for( int i = 1; i <= n; ++i )
		{
			cin >> arr[ i ];		
		}
		solve();
		cout << "\n";
	}	
	return 0;
}
