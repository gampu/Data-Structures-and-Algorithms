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

// Optimal Binary Search Tree 

int n;
vector< int > keys( 203 ), freq( 203 ), pre( 203, 0 );
int dp[ 203 ][ 203 ], ans[ 203 ][ 203 ];
vector< vector< int > > tree( 203 );

int solve( int l, int r )
{
	if( l > r )
	{
		return 0;
	}
	if( dp[ l ][ r ] != -1 )
	{
		return dp[ l ][ r ];
	}
	dp[ l ][ r ] = 1e9;
	for( int i = l; i <= r; ++i )
	{
		int res = freq[ i ] + solve( l, i - 1 ) + solve( i + 1, r ) + pre[ i - 1 ] - pre[ l - 1 ] + pre[ r ] - pre[ i ];
		if( dp[ l ][ r ] > res )
		{
			dp[ l ][ r ] = res;
			ans[ l ][ r ] = i;
		} 
	}
	return dp[ l ][ r ];
}

void print( int l, int r, int level )
{
	if( l > r )
	{
		return;
	}
	tree[ level ].emplace_back( ans[ l ][ r ] );
	print( l, ans[ l ][ r ] - 1, level + 1 );
	print( ans[ l ][ r ] + 1, r, level + 1 );
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	memset( dp, -1, sizeof( dp ) );
	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		cin >> keys[ i ];
	}
	for( int i = 1; i <= n; ++i )
	{
		cin >> freq[ i ];		
	}
	for( int i = 1; i <= n; ++i )
	{
		pre[ i ] += freq[ i ] + pre[ i - 1 ];
	}
	cout << solve( 1, n ) << "\n";
	print( 1, n, 1 );
	for( int i = 1; tree[ i ].size(); ++i )
	{
		for( int key : tree[ i ] )
		{
			cout << key << " ";
		}
		cout << "\n";
	}
	return 0;
}
