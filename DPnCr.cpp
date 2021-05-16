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

// nCr modulo ( 1e9 + 7 )

int t, n, r, m = 1e9 + 7;
vector< vector< long long > > c( 1005, vector< long long >( 1005 ) );

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	c[ 0 ][ 0 ] = 1;
	for( int i = 1; i <= 1000; ++i )
	{
		c[ i ][ 0 ] = c[ i ][ i ] = 1;
		for( int j = 1; j <= i - 1; ++j )
		{
			c[ i ][ j ] = ( c[ i - 1 ][ j - 1 ] + c[ i - 1 ][ j ] ) % m;
		}
	}
	cin >> t;
	for( int z = 0; z <= t - 1; ++z )
	{
		cin >> n >> r;
		cout << c[ n ][ r ] << "\n";	
	}	
	return 0;
}
