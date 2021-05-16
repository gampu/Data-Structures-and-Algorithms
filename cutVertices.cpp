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

// O( n + m ) algorithm for finding articulation points
// Input consists of undirected graph 

const int N = 1e5 + 5;
int n, m, k = 1, a, b;
vector< int > num( N, 0 ), pred( N, 0 );
vector< vector< int > > adj( N );
set< int > ans; // contains all cut vertices

void dfs( int v, int par )
{
	int children = 0;
	num[ v ] = pred[ v ] = k;
	++k;
	for( int u : adj[ v ] )
	{
		if( u != par )
		{
			if( num[ u ] == 0 )
			{
				++children;
				dfs( u, v );
				if( pred[ u ] >= num[ v ] and par != -1 )
				{	
					ans.insert( v );
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
	if( par == -1 and children > 1 )
	{
		ans.insert( v );
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
		for( int c : ans )
		{
			cout << c + 1 << " ";
		}
		cout << endl;
	}
	return 0;
}
