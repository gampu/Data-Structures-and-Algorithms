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

// QuickSort Algorithm

int n;
vector< int > arr( 2e6 + 6 );

int partition( int low, int high )
{
	int pos = low - 1;
	for( int i = low; i <= high - 1; ++i )
	{
		if( arr[ i ] < arr[ high ] )
		{
			++pos;
			swap( arr[ i ], arr[ pos ] );
		}
	}
	++pos;
	swap( arr[ pos ], arr[ high ] );
	return pos;
}

void quickSort( int low, int high )
{
	if( is_sorted( arr.begin() + low, arr.begin() + high + 1 ) )
	{
		return;
	}
	if( low < high )
	{
		int pos = partition( low, high );
		quickSort( low, pos - 1 );
		quickSort( pos + 1, high );
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	srand( time( NULL ) );
	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		arr[ i ] = rand();
	}
	quickSort( 1, n );
	cout << ( is_sorted( arr.begin() + 1, arr.begin() + n + 1 ) ? "YES" : "NO" ) << "\n";
	return 0;
}
