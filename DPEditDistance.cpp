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

string s1, s2;
int dp[ 105 ][ 105 ];

int solve( int i, int j )
{
	if( i == -1 && j == -1 )
	{
		return 0;
	}
	if( i == -1 && j != -1 )
	{
		return j + 1;
	}
	if( i != -1 && j == -1 )
	{
		return i + 1;
	}
	if( dp[ i ][ j ] != -1 )
	{
		return dp[ i ][ j ];
	}
	if( s1[ i ] == s2[ j ] )
	{
		dp[ i ][ j ] = solve( i - 1, j - 1 );
	}
	else
	{
		dp[ i ][ j ] = min( { 1 + solve( i - 1, j - 1 ), 1 + solve( i, j - 1 ), 1 + solve( i - 1, j ) } );
	}
	return dp[ i ][ j ];
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	memset( dp, -1, sizeof( dp ) );
	cin >> s1 >> s2;
	cout << solve( s1.length() - 1, s2.length() - 1 ) << "\n";
	return 0;
}
