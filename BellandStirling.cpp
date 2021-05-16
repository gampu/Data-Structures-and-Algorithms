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

int n;
long long int dp[ 1003 ][ 1003 ], bell = 0, m = 1e9 + 7;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	memset( dp, 0, sizeof( dp ) );
	cin >> n;
	dp[ 1 ][ 1 ] = 1;
	for( int i = 2; i <= n; ++i )
	{
		for( int j = 1; j <= i; ++j )
		{
			dp[ i ][ j ] = ( j * dp[ i - 1 ][ j ] % m + dp[ i - 1 ][ j - 1 ] % m ) % m;
		}
	}
	for( int i = 1; i <= n; ++i )
	{
		bell += dp[ n ][ i ];
		bell %= m;
	}
	cout << bell << "\n";
	return 0;
}
