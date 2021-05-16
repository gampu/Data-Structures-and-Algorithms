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

// Comb Sort

bool con = true;
int n, step;
vector< int > arr( 6e6 + 6 );

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	srand( time( NULL ) );
	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		arr[ i ] = rand() % 100;		
	}
	step = n;
	while( ( step = ( step / 1.3 ) ) >= 2 )
	{
		for( int j = n; j >= step + 1; --j )
		{
			if( arr[ j - step ] > arr[ j ] )
			{
				swap( arr[ j - step ], arr[ j ] );
			}
		}
	}
	for( int i = 1; con && i <= n - 1; ++i )
	{
		con = false;
		for( int j = n - 1; j >= i; --j )
		{
			if( arr[ j ] > arr[ j + 1 ] )
			{
				swap( arr[ j ], arr[ j + 1 ] );
				con = true;
			}
		}
	}
	cout << ( is_sorted( arr.begin() + 1, arr.begin() + n + 1 ) ? "YES" : "NO" ) << "\n";		
	return 0;
}
