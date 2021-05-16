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
vector< char > ans;
set< string > s;
int dp[ 1005 ][ 1005 ];

int solve( int i, int j )
{
	if( i == -1 || j == -1 )
	{
		return 0;
	}
	if( dp[ i ][ j ] != -1 )
	{
		return dp[ i ][ j ];
	}
	if( s1[ i ] == s2[ j ] )
	{
		dp[ i ][ j ] = 1 + solve( i - 1, j - 1 );
	}
	else
	{
		dp[ i ][ j ] = max( solve( i - 1, j ), solve( i, j - 1 ) );
	}
	return dp[ i ][ j ];
}

void print( int i, int j )
{
	if( i == -1 || j == -1 )
	{	
		s.insert( string( ans.rbegin(), ans.rend() ) );
		return;
	}
	if( s1[ i ] == s2[ j ] )
	{
		ans.push_back( s1[ i ] );
		print( i - 1, j - 1 );
		ans.pop_back();
	}
	else
	{
		if( dp[ i ][ j ] == solve( i - 1, j ) )
		{
			print( i - 1, j );
		}
		if( dp[ i ][ j ] == solve( i, j - 1 ) )
		{
			print( i, j - 1 );
		}
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	memset( dp, -1, sizeof( dp ) );
	cin >> s1 >> s2;
	cout << solve( s1.length() - 1, s2.length() - 1 ) << "\n";
	print( s1.length() - 1, s2.length() - 1 );
	cout << s.size() << "\n";
	for( string val : s )
	{
		cout << val << "\n";
	}
	return 0;
}
