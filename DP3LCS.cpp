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

int t, n, m, o;
string s1, s2, s3;
int dp[ 105 ][ 105 ][ 105 ];

int solve( int i, int j, int k )
{
	if( i == -1 || j == -1 || k == -1 )
	{
		return 0;
	}
	if( dp[ i ][ j ][ k ] != -1 )
	{
		return dp[ i ][ j ][ k ];
	}
	if( s1[ i ] == s2[ j ] && s2[ j ] == s3[ k ] )
	{
		dp[ i ][ j ][ k ] = 1 + solve( i - 1, j - 1, k - 1 );
	}
	else
	{
		dp[ i ][ j ][ k ] = max( solve( i - 1, j, k ), max( solve( i, j - 1, k ), solve( i, j, k - 1 ) ) );
	}
	return dp[ i ][ j ][ k ];
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 0; z <= t - 1; ++z )
	{
		memset( dp, -1, sizeof( dp ) );
		cin >> n >> m >> o;
		cin >> s1 >> s2 >> s3;
		cout << solve( n - 1, m - 1, o - 1 ) << "\n";
	}	
	return 0;
}
