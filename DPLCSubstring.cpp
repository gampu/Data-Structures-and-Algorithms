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

// find the longest common substring(s) of the two input strings

int ans = 0;
string s1, s2;
int dp[ 105 ][ 105 ];

int solve( int i, int j ) // kind of similar to longest common subsequence but break contiguity when elements are different.
{
	if( i < 0 || j < 0 )
	{
		return 0;
	}
	if( dp[ i ][ j ] != -1 )
	{
		return dp[ i ][ j ];
	}
	dp[ i ][ j ] = 0;
	if( s1[ i ] == s2[ j ] )
	{
		dp[ i ][ j ] = 1 + solve( i - 1, j - 1 );
	}
	ans = max( ans, dp[ i ][ j ] );
	ans = max( ans, solve( i - 1, j ) );
	ans = max( ans, solve( i, j - 1 ) );
	return dp[ i ][ j ];
}

void print( void ) // print all solutions
{
	for( int i = 0; i <= s1.length() - 1; ++i )
	{
		for( int j = 0; j <= s2.length() - 1; ++j )
		{
			if( dp[ i ][ j ] == ans )
			{
				cout << s1.substr( i + 1 - ans, ans ) << "\n"; // insert these substrings in a set to get unique ones
			}
		}
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	memset( dp, -1, sizeof( dp ) );
	cin >> s1 >> s2; // just input two strings
	solve( s1.length() - 1, s2.length() - 1 );
	cout << ans << "\n";
	print();
	return 0;
}
