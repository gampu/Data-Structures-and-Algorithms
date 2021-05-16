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

// Codeforces 988 E
// Without making the first digit of n as zero, swap any two adjacent digits in n so that n is divisible by 25. Find out 
// the minimum number of such swaps required. If it is impossible to do so, print -1;

int i, j, k, z, n, ans = 1e9, cnt;
string s, cpy;

void check( int a, int b )
{
	cnt = 0;
	cpy = s;
	for( int x = b; x <= n - 2; ++x )
	{
		++cnt;
		swap( cpy[ x ], cpy[ x + 1 ] );
	}
	for( int x = a; x <= n - 3; ++x )
	{
		++cnt;
		swap( cpy[ x ], cpy[ x + 1 ] );
	}
	if( cpy[ 0 ] == '0' )
	{
		for( z = 1; z <= n - 1; ++z )
		{
			if( cpy[ z ] != '0' )
			{
				break;
			}
		}
		cnt += z;
	}
}

void update( void )
{
	if( i == -1 || j == -1 )
	{
		return;
	}
	if( i < j )
	{
		check( i, j );
		ans = min( ans, cnt );
	}
	else
	{
		check( i - 1, j );
		ans = min( ans, cnt );
	}
}

void solve( char a, char b )
{	
	i = j = -1;
	for( k = n - 1; k >= 0; --k )
	{
		if( s[ k ] == b )
		{
			j = k;
			break;
		}
	}
	for( k = n - 1; k >= 0; --k )
	{
		if( s[ k ] == a )
		{
			i = k;
			break;
		}
	}
	update();
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> s;
	n = s.length();
	solve( '7', '5' );
	solve( '5', '0' );
	solve( '2', '5' );
	i = j = -1;
	for( k = n - 1; k >= 0; --k )
	{
		if( s[ k ] == '0' )
		{
			j = k;
			break;
		}
	}
	for( k = j - 1; k >= 0; --k )
	{
		if( s[ k ] == '0' )
		{
			i = k;
			break;
		}
	}
	update();
	if( ans == 1e9 )
	{
		ans = -1;
	}
	cout << ans << "\n";
	return 0;
}
