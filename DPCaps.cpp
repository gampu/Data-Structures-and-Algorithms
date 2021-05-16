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

// Bitmasking and Combinatorics on Caps
// https://www.codechef.com/problems/TSHIRTS

int t, n, id, mod = 1e9 + 7;
string s;
stringstream ss;
vector< vector< int > > arr( 101 );
long long dp[ 1 << 11 ][ 101 ];

long long solve( int mask, int cap, int cnt )
{
	if( cap == 0 )
	{
		if( cnt == n )
		{
			return 1;
		}
		return 0;
	}
	if( dp[ mask ][ cap ] != -1 )
	{
		return dp[ mask ][ cap ];
	}
	long long res = 0;
	for( int person : arr[ cap ] )
	{
		if( !( mask & ( 1 << person ) ) )
		{
			res += solve( mask | ( 1 << person ), cap - 1, cnt + 1 );
			res %= mod;
		}
	}
	res += solve( mask, cap - 1, cnt );
	res %= mod;
	return dp[ mask ][ cap ] = res;
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	cin.ignore();
	for( int z = 1; z <= t; ++z )
	{
		memset( dp, -1, sizeof( dp ) );
		fill( arr.begin(), arr.end(), vector< int >() );
		cin >> n;
		cin.ignore();
		for( int i = 1; i <= n; ++i )
		{
			getline( cin, s );
			ss = stringstream( s );
			while( ss >> id )
			{
				arr[ id ].emplace_back( i );
			}		
		}
		cout << solve( 0, 100, 0 ) << "\n";
	}		
	return 0;
}
