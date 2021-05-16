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

int n;
vector< int > arr( 3e6 + 6 );

void quicksort( int first, int last )
{
	if( first == last )
	{
		return;
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
	quicksort( first, l - 1 );
	quicksort( l, last );
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	srand( time( 0 ) );

	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		arr[ i ] = rand() % 100;
	}
	quicksort( 1, n );
	cout << ( is_sorted( arr.begin() + 1, arr.begin() + n + 1 ) ? "YES" : "NO" ) << "\n";
	return 0;
}
