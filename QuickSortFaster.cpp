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
vector< int > arr( 2e5 + 5 );

void quicksort( int l, int r )
{
	if( l >= r )
	{
		return;
	}
	int bound = arr[ ( l + r ) >> 1 ], cnt = 0, a, b, pos;
	vector< int > lt, gt;
	for( int i = l; i <= r; ++i )
	{
		if( arr[ i ] < bound )
		{
			lt.emplace_back( arr[ i ] );
		}
		else if( arr[ i ] > bound )
		{
			gt.emplace_back( arr[ i ] );
		}
		else
		{
			++cnt;
		}
	}
	a = lt.size(); b = gt.size();
	pos = l;
	for( int i = 0; i <= a - 1; ++i, ++pos )
	{
		arr[ pos ] = lt[ i ];
	}
	for( int i = 1; i <= cnt; ++i, ++pos )
	{
		arr[ pos ] = bound;
	}
	for( int i = 0; i <= b - 1; ++i, ++pos )
	{
		arr[ pos ] = gt[ i ];
	}
	lt.clear(); gt.clear();
	quicksort( l, a + l - 1 );
	quicksort( r - b + 1, r );
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	srand( time( 0 ) );

	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		arr[ i ] = rand();
	}
	random_shuffle( arr.begin() + 1, arr.begin() + n + 1 );
	quicksort( 1, n );
	cout << ( is_sorted( arr.begin() + 1, arr.begin() + n + 1 ) ? "YES" : "NO" ) << "\n";
	return 0;
}
