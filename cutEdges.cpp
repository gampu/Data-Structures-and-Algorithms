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
#include<cstring>
using namespace std;

// O( n + m ) algorithm for finding cut edges
// Input consists of undirected graph 

const int N = 1e5 + 5;
int n, m, k = 1, a, b;
vector< int > num( N, 0 ), pred( N, 0 );
vector< vector< int > > adj( N );
set< pair< int, int > > ans; // contains all bridges

void dfs( int v, int par )
{
	num[ v ] = pred[ v ] = k;
	++k;
	for( int u : adj[ v ] )
	{
		if( u != par )
		{
			if( num[ u ] == 0 )
			{
				dfs( u, v );
				if( pred[ u ] > num[ v ] )
				{	
					ans.insert( { v, u } );
				}
				else
				{
					pred[ v ] = min( pred[ v ], pred[ u ] );
				}
			}
			else
			{
				pred[ v ] = min( pred[ v ], num[ u ] );
			}
		}
	}
}
				
int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> m;
	for( int i = 1; i <= m; ++i )
	{	
		cin >> a >> b; // edges are of 1-indexed
		--a;
		--b;
		adj[ a ].emplace_back( b );
		adj[ b ].emplace_back( a );
	}
	for( int i = 0; i <= n - 1; ++i )
	{	
		if( num[ i ] == 0 )
		{
			dfs( i, -1 );
		}		
	}
	if( ans.size() == 0 )
	{
		cout << -1 << endl;
	}
	else
	{
		for( auto c : ans )
		{
			cout << c.first + 1 << " " << c.second + 1 << endl;
		}
	}
	return 0;
}
