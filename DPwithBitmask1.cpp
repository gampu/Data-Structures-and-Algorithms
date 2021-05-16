#pragma GCC optimize( "Ofast" )

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

// https://cses.fi/problemset/task/1690/
// Total number of paths from 1 to n in a directed path such that it goes through all vertices modulo 1e9 + 7

int n, m, a, b, mod = 1e9 + 7;
vector< vector< int > > arr( 21 );
long long dp[ 1 << 20 ][ 21 ];

long long solve( int mask, int last, int cnt )
{
	if( last == n )
	{
		return ( cnt == n ? 1 : 0 );
	}
	if( cnt == n )
	{
		return 0;
	}
	if( dp[ mask ][ last ] != -1 )
	{
		return dp[ mask ][ last ];
	}
	long long ans = 0;
	for( int v : arr[ last ] )
	{
		if( !( mask & ( 1 << ( v - 1 ) ) ) )
		{
			ans += solve( mask | ( 1 << ( v - 1 ) ), v, cnt + 1 );
			if( ans >= mod )
			{
				ans %= mod;
			}
		}		
	}
	return dp[ mask ][ last ] = ans;
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	memset( dp, -1, sizeof( dp ) );
	cin >> n >> m;
	for( int i = 1; i <= m; ++i )
	{
		cin >> a >> b;
		arr[ a ].emplace_back( b );
	}
	cout << solve( 0 | ( 1 << 0 ), 1, 1 ) << "\n";	
	return 0;
}
