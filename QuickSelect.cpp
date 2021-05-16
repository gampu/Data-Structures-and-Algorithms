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
#include<cassert>
using namespace std;

int n, k;
vector< int > arr( 3e6 + 6 );

int quickselect( int first, int last, int k )
{
	if( first == last )
	{
		return arr[ first ];
	}
	int l = first, r = last, bound = arr[ ( l + r ) >> 1 ];
	while( l <= r )
	{
		while( l <= r && arr[ l ] < bound )
		{
			++l;
		}
		while( l <= r && arr[ r ] > bound )
		{
			--r;
		}
		if( l <= r )
		{
			swap( arr[ l ], arr[ r ] );
			++l;
			--r;
		}
	}
	if( l - first < k )
	{
		return quickselect( l, last, k - ( l - first ) );
	}
	return quickselect( first, l - 1, k );
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );

	cin >> n >> k;
	for( int i = 1; i <= n; ++i )
	{
		cin >> arr[ i ];
	}	
	cout << quickselect( 1, n, k ) << "\n";
	return 0;
}
