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

// Shell Sort

int n, h, mx, pos, swp, cur;
vector< int > arr( 2e5 + 5 ), inc( 50 );

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	srand( time( NULL ) );

	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		arr[ i ] = rand() % 1000;
	}
	for( h = 1, mx = 1; h < n; ++mx )
	{
		inc[ mx ] = h;
		h = 3 * h + 1;
	}
	for( int i = mx - 1; i >= 1; --i )
	{
		h = inc[ i ];
		for( int j = 1; j <= h; ++j )
		{
			pos = j + h;
			while( pos <= n )
			{
				swp = arr[ pos ];
				cur = pos;
				while( cur - h >= j && arr[ cur - h ] > swp )
				{
					arr[ cur ] = arr[ cur - h ];
					cur -= h;
				}
				arr[ cur ] = swp;
				pos += h;
			}	
		}
	}
	cout << ( is_sorted( arr.begin() + 1, arr.begin() + n + 1 ) ? "YES" : "NO" ) << "\n";
	return 0;
}
