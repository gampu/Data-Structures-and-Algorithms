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

// Matrix Chain Multiplication Problem
// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0
// https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication/0/?ref=self

int t, n;
vector< long long > arr( 105 );
int res[ 105 ][ 105 ];
long long dp[ 105 ][ 105 ];

long long solve( int l, int r )
{	
	if( l == r )
	{
		return 0;
	}
	if( dp[ l ][ r ] != -1 )
	{
		return dp[ l ][ r ];
	}
	dp[ l ][ r ] = 1e18;
	for( int i = l; i <= r - 1; ++i )
	{
		if( dp[ l ][ r ] > solve( l, i ) + solve( i + 1, r ) + arr[ l - 1 ] * arr[ i ] * arr[ r ] )
		{
			dp[ l ][ r ] = solve( l, i ) + solve( i + 1, r ) + arr[ l - 1 ] * arr[ i ] * arr[ r ];
			res[ l ][ r ] = i;
		}
	}
	return dp[ l ][ r ];
}

void print( int l, int r )
{
	if( l == r )
	{
		cout << char( 65 + l - 1 );
		return;
	}
	cout << '(';
	print( l, res[ l ][ r ] );
	print( res[ l ][ r ] + 1, r );
	cout << ')';
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 1; z <= t; ++z )
	{
		memset( dp, -1, sizeof( dp ) );
		cin >> n;
		--n;
		for( int i = 0; i <= n; ++i )
		{
			cin >> arr[ i ];
		}
		solve( 1, n ); // Optimal Cost
		print( 1, n ); // Optimal Solution
		cout << "\n";
	}	
	return 0;
}
