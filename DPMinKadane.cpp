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

int t, n, best, sum;
vector< int > arr( 1e4 + 4 );

int main( void )
{
	cin >> t; // number of testcases
	for( int z = 0; z <= t - 1; ++z )
	{
		cin >> n; // size of the input array
		for( int i = 0; i <= n - 1; ++i )
		{
			cin >> arr[ i ];		
		}
		best = sum = arr[ 0 ];
		for( int i = 1; i <= n - 1; ++i )
		{
			if( arr[ i ] < sum + arr[ i ] )
			{
				sum = arr[ i ];
			}
			else
			{
				sum += arr[ i ];
			}
			best = min( best, sum );
		}
		cout << best << "\n"; // the required answer
	}	    
	return 0;
} 
