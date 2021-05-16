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

ostream_iterator< int > output( cout, " " );
int n, pre, res = -1;
vector< int > arr( 100, -1 ), dp( 100, -1 ), ans;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 0; i <= n - 1; ++i )
	{
		cin >> arr[ i ];
	}
	sort( arr.begin(), arr.begin() + n );
	for( int i = 0; i <= n - 1; ++i )
	{
		dp[ i ] = 1;
		pre = arr[ i ];
		for( int j = i + 1; j <= n - 1; ++j )
		{
			if( arr[ j ] % pre == 0 )
			{
				++dp[ i ];
				pre = arr[ j ];
			}
		}
		res = max( res, dp[ i ] );	
	}
	cout << "\n" << res << "\n";
	for( int i = 0; i <= n - 1; ++i )
	{
		if( dp[ i ] == res )
		{
			ans.clear();
			ans.emplace_back( arr[ i ] );
			pre = arr[ i ];
			for( int j = i + 1; j <= n - 1; ++j )
			{
				if( arr[ j ] % pre == 0 )
				{			
					ans.emplace_back( arr[ j ] );
					pre = arr[ j ];
				}
			}
			copy( ans.begin(), ans.end(), output );
			cout << "\n";
		}
	}
	return 0;
}
/*
5
10 5 3 15 20

3
5 10 20 


6
18 1 3 6 13 17

4
1 3 6 18 


8
100 81 50 27 25 9 5 3

4
3 9 27 81 
5 25 50 100
*/
