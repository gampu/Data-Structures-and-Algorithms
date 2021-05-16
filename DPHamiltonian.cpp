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

// Given a directed and weighted graph, find whether there exists a Hamiltonian Cycle in it?
// i.e. to say, whether there exists a cycle that visits every city exactly once and returns to the start position.
// Initially, all n * ( n - 1 ) edges are assumed to not exist( i.e. have weight as inf = 1e9 )

int n, m, a, b, w, ans = 1e9;
int dp[ 1 << 20 ][ 20 ];
vector< vector< int > > cost( 20, vector< int >( 20, 1e9 ) );

int solve( int mask, int last, int start, int cnt )
{
	if( cnt == n )
	{
		return cost[ last ][ start ];
	}
	if( dp[ mask ][ last ] != -1 )
	{	
		return dp[ mask ][ last ];
	}
	int res = 1e9;
	for( int i = 1; i <= n; ++i )
	{
		if( !( mask & ( 1 << i ) ) )
		{
			res = min( res, cost[ last ][ i ] + solve( mask | ( 1 << i ), i, ( start == 0 ? i : start ), cnt + 1 ) );
		}
	}
	return dp[ mask ][ last ] = res;
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	memset( dp, -1, sizeof( dp ) );
	cin >> n >> m;
	for( int i = 1; i <= m; ++i )
	{
		cin >> a >> b >> w;
		cost[ a ][ b ] = w;
	}

	// Method 1
	for( int i = 1; i <= n; ++i )
	{
		ans = min( ans, solve( 0 | ( 1 << i ), i, i, 1 ) );
		cout << solve( 0 | ( 1 << i ), i, i, 1 ) << "\n";
	}
	cout << ( ans < 1e9 ? "Yes" : "No" ) << "\n";
	cout << ans << "\n";

	// Method 2
	fill( cost[ 0 ].begin(), cost[ 0 ].end(), 0 );
	ans = solve( 0, 0, 0, 0 );
	cout << ans << "\n";
	return 0;
}

