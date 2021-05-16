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
using namespace std;

int t, n, m, val;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 0; z <= t - 1; ++z )
	{
		cin >> n >> m;
		set< int > s;
		vector< int > dp( n + 5, 1e9 );
		dp[ 0 ] = 0;
		for( int i = 0; i <= m - 1; ++i )
		{
			cin >> val;
			s.insert( val );
		}
		for( int i = 1; i <= n; ++i )
		{
			for( int c : s )
			{
				if( i - c >= 0 )
				{
					dp[ i ] = min( dp[ i ], 1 + dp[ i - c ] );
				}
				else
				{
					break;
				}
			}
		}
		if( dp[ n ] == 1e9 )
		{
			dp[ n ] = -1;
		}
		cout << dp[ n ] << "\n";
	}	
	return 0;
}
