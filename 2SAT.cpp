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
using namespace std;

// 2-SAT algorithm to find valid assignment of boolean values to variables in a boolean expression
// O( 2 * variables + 2 * clauses )

int n, m, a, b, cnt = 0, N = 1e5 + 5;
vector< vector< int > > adj( N ), tadj( N );
vector< int > num( N, 0 ), comp( N, 0 ), sol( N, 0 ), topo, scc;

void dfs1( int u )
{
	num[ u ] = 1;
	for( int v : adj[ u ] )
	{
		if( num[ v ] == 0 )
		{
			dfs1( v );
		}
	}
	topo.emplace_back( u );
}

void dfs2( int u )
{
	num[ u ] = 1;
	scc.emplace_back( u );
	for( int v : tadj[ u ] )
	{
		if( num[ v ] == 0 )
		{
			dfs2( v );
		}
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> m; //n is 2 times the no. of variables in the boolean expression and m is the no. of edges in the implication graph
	for( int i = 1; i <= m; ++i )
	{
		cin >> a >> b; // 1 based vertex numbering
		adj[ a ].emplace_back( b );
		tadj[ b ].emplace_back( a );
	}
	for( int i = 1; i <= n; ++i )
	{
		if( num[ i ] == 0 )
		{
			dfs1( i );
		}		
	}
	fill( num.begin(), num.end(), 0 );
	for( int i = n - 1; i >= 0; --i )
	{
		if( num[ topo[ i ] ] == 0 )
		{
			scc.clear();
			++cnt;
			dfs2( topo[ i ] );
			for( int u : scc )
			{
				comp[ u ] = cnt;
			}
		}
	}
	for( int i = 1; i <= n / 2; ++i )
	{
		if( comp[ 2 * i - 1 ] == comp[ 2 * i ] )
		{
			cout << "No solution exists." << "\n";
			return 0;
		}
		sol[ i ] = comp[ 2 * i - 1 ] > comp[ 2 * i ];
	}
	for( int i = 1; i <= n / 2 ; ++i )
	{
		cout << sol[ i ] << " \n"[ i == n / 2 ];		
	}
	return 0;
}
/*
ex. ( a v !b ) ^ ( !a v b ) ^ ( !a v !b ) ^ ( a v !c )
6 8
5 1
1 4
1 3
3 1
4 2
2 4
3 2
2 6

0 0 0


ex. ( a v !b ) ^ ( !a v !b ) ^ ( b v !a ) 
6 6
2 3
3 1
1 4
3 2
4 2
1 3

No solution exists.
*/
