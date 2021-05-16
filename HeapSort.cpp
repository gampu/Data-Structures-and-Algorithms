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

// Heap Class + Priority_Queue + HeapSort
template< typename T >
class Heap
{
	public:
		int n = 0;
		vector< T > heap = vector< T >( 2e5 + 5 );
	
		T getMax( void )
		{
			return heap[ 1 ];
		}

		void enqueue( T val )
		{
			++n;
			heap[ n ] = val;
			int pos = n, par = pos / 2;
			while( par != 0 && heap[ par ] < heap[ pos ] )
			{
				swap( heap[ par ], heap[ pos ] );
				pos = par;
				par = pos / 2;
			}
		}

		void dequeue( void )
		{
			swap( heap[ 1 ], heap[ n ] );
			--n;
			int pos = 1, lft = 2 * pos, mx;
			while( lft <= n )
			{
				mx = lft;
				if( lft + 1 <= n && heap[ mx ] < heap[ lft + 1 ] )
				{
					mx = lft + 1;
				}
				if( heap[ pos ] >= heap[ mx ] )
				{
					return;
				}
				swap( heap[ pos ], heap[ mx ] );
				pos = mx;
				lft = 2 * pos;
			}
		}
};

int n;
vector< int > arr( 2e5 + 5 ), ans( 2e5 + 5 );

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );

	srand( time( NULL ) );

	Heap< int > heap;	
	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		arr[ i ] = rand() % 100;
		heap.enqueue( arr[ i ] );
	}
	for( int i = n; i >= 1; --i )
	{
		ans[ i ] = heap.getMax();
		heap.dequeue();		
	}
	for( int i = 1; i <= n; ++i )
	{
		cout << ans[ i ] << " \n"[ i == n ];		
	}
	return 0;
}
