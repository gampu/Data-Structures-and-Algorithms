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

// Given a complete undirected and weighted graph( i.e. to say, Many Hamiltonian Cycles exist ), find the Hamiltonian Cycle 
// with the least cost.
// i.e. to compute, the cost of a cycle that visits every city exactly once and returns to the start position.

int n, a, b, w;
int dp[ 1 << 20 ][ 20 ];
vector< vector< int > > cost( 20, vector< int >( 20, 0 ) );

int solve( int mask, int last, int start, int cnt )
{
	if( cnt == n )
	{
		return cost[ last ][ start ];
	}
	if( dp[ mask ][ last ] != -1 )
	{	
		return dp[ mask ][ last ];
	}
	int res = 1e9;
	for( int i = 1; i <= n; ++i )
	{
		if( !( mask & ( 1 << i ) ) )
		{
			res = min( res, cost[ last ][ i ] + solve( mask | ( 1 << i ), i, ( start == 0 ? i : start ), cnt + 1 ) );
		}
	}
	return dp[ mask ][ last ] = res;
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	memset( dp, -1, sizeof( dp ) );
	cin >> n;
	for( int i = 1; i <= n * ( n - 1 ) / 2; ++i )
	{
		cin >> a >> b >> w;
		cost[ a ][ b ] = w;
		cost[ b ][ a ] = w; // Symmetrical
	}
	cout << solve( 0, 0, 0, 0 ) << "\n";
	for( int i = 1; i <= n; ++i ) // Illustrates method for Cycles starting from each i: 1 <= i <= n
	{
		cout << solve( 0 | ( 1 << i ), i, i, 1 ) << "\n";		
	}
	return 0;
}
/*
4
1 2 10
1 3 15
1 4 20
2 3 35
2 4 25
3 4 30
70 		Main Answer
80		Shortest TSP Cycle from 1 to 1
75		Shortest TSP Cycle from 2 to 2
70		Shortest TSP Cycle from 3 to 3
80		Shortest TSP Cycle from 4 to 4
*/	
