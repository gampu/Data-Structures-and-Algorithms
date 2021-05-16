#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<utility>
#include<functional>
#include<bitset>
#include<cstring>
using namespace std;

// The input graph consists of no loops and multiple edges

vector< vector< int > > adj( 1e5 + 5 );
vector< int > num( 1e5 + 5, 0 );
vector< int > parent( 1e5 + 5, -1 );

void dfs( int u )
{
	num[ u ] = 1;
	for( int v : adj[ u ] )
	{
		if( num[ v ] == 0 )
		{
			parent[ v ] = u;
			dfs( v );
		}
		else if( num[ v ] == 1 /*and parent[ u ] != v*/ )
		{
			cout << "Cycle Found" << endl;
			cout << v + 1 << " " << u + 1 << " ";
			while( parent[ u ] != v )
			{
				cout << parent[ u ] + 1 << " ";
				u = parent[ u ] ;
			}
			cout << v + 1 << endl;
			exit( EXIT_SUCCESS );
		}
	}
	num[ u ] = 2;
}

int main( void )
{
	int n, m, u, v;
	cin >> n >> m;
	for( int i = 1; i <= m; ++i )
	{
		cin >> u >> v;
		--u;
		--v;
		adj[ u ].emplace_back( v );
	}
	for( int i = 0; i <= n - 1; ++i )
	{	
		if( num[ i ] == 0 )
		{
			dfs( i );
		}		
	}
	cout << "No Cycle found" << endl;
	return 0;
}
