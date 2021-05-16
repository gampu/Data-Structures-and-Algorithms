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

// Kosaraju's Algorithm to find the SCCs of a directed graph
// O( n + m )

int n, m, a, b, cnt = 0, N = 1e5 + 5;
vector< vector< int > > adj( N ), tadj( N );
vector< int > num( N, 0 ), topo, scc;

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
	
	cin >> n >> m;
	for( int i = 0; i <= m - 1; ++i )
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
				cout << u << " ";
			}
			cout << "\n";
		}
	}
	cout << "Ans: " << cnt << "\n"; // total count of SCCs
	return 0;
}
