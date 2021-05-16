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

// Given a rod of length n and an array that contains prices of all pieces of size smaller than or equal to n. Determine 
// the maximum value obtainable by cutting up the rod and selling the pieces.

int n;
vector< int > arr( 101, 0 ), dp( 101, -1 ), ans;

int solve( int n )
{
	if( n == 0 )
	{
		return arr[ n ];
	}
	if( dp[ n ] != -1 )
	{
		return dp[ n ];
	}
	for( int i = 1; i <= n; ++i )
	{
		dp[ n ] = max( dp[ n ], arr[ i ] + solve( n - i ) );
	}
	return dp[ n ];
}
// For a rod of length n, cut a piece of length i from it's right side and then solve for n - i. Update using max.

void print( int n )
{
	if( n == 0 )
	{
		for( int val : ans )
		{
			cout << val << " ";
		}
		cout << "\n";
		return;
	}
	for( int i = 1; i <= n; ++i )
	{
		if( dp[ n ] == arr[ i ] + solve( n - i ) ) // Print all solutions
		{
			ans.emplace_back( i );
			print( n - i );
			ans.pop_back();
		}
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
		
	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		cin >> arr[ i ];
	}
	cout << solve( n ) << "\n";
	print( n );
	return 0;
}
