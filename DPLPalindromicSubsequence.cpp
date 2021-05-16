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

string s;
int dp[ 1005 ][ 1005 ];
vector< char > ans;
set< string > palin;

int solve( int i, int j )
{
	if( i > j )
	{
		return 0;
	}
	if( i == j )
	{
		return 1;
	}
	if( dp[ i ][ j ] != -1 )
	{
		return dp[ i ][ j ];
	}
	if( s[ i ] == s[ j ] )
	{
		dp[ i ][ j ] = 2 + solve( i + 1, j - 1 );
	}
	else
	{
		dp[ i ][ j ] = max( solve( i, j - 1 ), solve( i + 1, j ) );
	}
	return dp[ i ][ j ];
}

void print( int i, int j )
{
	if( i > j )
	{
		palin.insert( string( ans.begin(), ans.end() ) + string( ans.rbegin(), ans.rend() ) );
		return;
	}
	if( i == j )
	{
		palin.insert( string( ans.begin(), ans.end() ) + s[ i ] + string( ans.rbegin(), ans.rend() ) );
		return;
	}
	if( s[ i ] == s[ j ] )
	{
		ans.push_back( s[ i ] );
		print( i + 1, j - 1 );
		ans.pop_back();
	}
	else
	{
		if( dp[ i ][ j ] == solve( i, j - 1 ) )
		{
			print( i, j - 1 );
		}
		if( dp[ i ][ j ] == solve( i + 1, j ) )
		{
			print( i + 1, j );
		}
	}
}
	
int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	memset( dp, -1, sizeof( dp ) );
	cin >> s;
	cout << solve( 0, s.length() - 1 ) << "\n";
	print( 0, s.length() - 1 );
	for( string str : palin )
	{
		cout << str << "\n";
	}
	return 0;
}
