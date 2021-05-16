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

// https://atcoder.jp/contests/dp/tasks/dp_s
// Number of digits from 1 to s such that the sum of their digits is a multiple of d

int n, d, mod = 1e9 + 7;
string s;
long long dp[ 10005 ][ 105 ][ 2 ];

long long solve( int pos, int sum, bool allowed )
{
	if( pos == n )
	{
		return !sum;
	}
	if( dp[ pos ][ sum ][ allowed ] != -1 )
	{
		return dp[ pos ][ sum ][ allowed ];
	}
	dp[ pos ][ sum ][ allowed ] = 0;
	for( int i = 0; i <= ( allowed ? 9 : s[ pos ] - '0' ); ++i )
	{
		dp[ pos ][ sum ][ allowed ] += solve( pos + 1, ( sum + i ) % d, ( allowed || i < ( s[ pos ] - '0' ) ) );
		if( dp[ pos ][ sum ][ allowed ] >= mod )
		{
			dp[ pos ][ sum ][ allowed ] -= mod;
		}
	}
	return dp[ pos ][ sum ][ allowed ];
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> s >> d;
	n = s.length();
	memset( dp, -1, sizeof( dp ) );
	cout << ( solve( 0, 0, 0 ) - 1 + mod ) % mod << "\n";
	return 0;
}

