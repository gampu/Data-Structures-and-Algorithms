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

// find the sum of a submatrix of a given matrix in O( 1 )
 
const int N = 1e3 + 3;
int n, m, q, a, b, c, d;
long long int dp[ N ][ N ], arr[ N ][ N ];

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	memset( dp, 0, sizeof( dp ) );
	cin >> n >> m;
	for( int i = 1; i <= n; ++i )
	{
		for( int j = 1; j <= m; ++j )
		{
			cin >> arr[ i ][ j ];
		}
	}
	for( int i = 1; i <= n; ++i )
	{
		for( int j = 1; j <= m; ++j )
		{
			dp[ i ][ j ] += dp[ i ][ j - 1 ] + arr[ i ][ j ];
		}
		for( int j = 1; j <= m; ++j )
		{
			dp[ i ][ j ] += dp[ i - 1 ][ j ];
		}
	}
	cin >> q;
	for( int i = 1; i <= q; ++i )
	{
		cin >> a >> b >> c >> d; // 1 indexed
		cout << dp[ c ][ d ] - dp[ a - 1 ][ d ] - dp[ c ][ b - 1 ] + dp[ a - 1 ][ b - 1 ] << "\n";
	}
	return 0;
}
/*
3 3 
1 2 3 
4 5 6
7 8 9 
3
1 1 3 3 
2 2 3 3 
2 1 3 2
45
28
24
*/
