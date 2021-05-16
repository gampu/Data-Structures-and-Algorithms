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

// O( n^2 ) Prim's Algorithm for computing the Minimum Spanning Tree

const int N = 1e3 + 3;
int n, a, b, m, w, total = 0;
vector< int > selected( N, 0 );
vector< vector< pair< int, int > > > adj( N );
vector< pair< int, int > > edge( N, { 1e9, -1 } ), ans;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> m;
	for( int i = 1; i <= m; ++i )
	{
		cin >> a >> b >> w; // 1-indexed
		adj[ a ].push_back( { b, w } );
		adj[ b ].push_back( { a, w } );
	}
	for( int i = 1; i <= n; ++i )
	{
		int v = -1;
		for( int j = 1; j <= n; ++j )
		{
			if( !selected[ j ] && ( v == -1 || edge[ j ].first < edge[ v ].first ) )
			{
				v = j;
			}
		}
		selected[ v ] = 1;
		if( edge[ v ].first == 1e9 && v != 1 )
		{
			cout << -1 << "\n";
			exit( EXIT_SUCCESS );
		}
		if( v != 1 )
		{
			ans.push_back( { v, edge[ v ].second } );
			total += edge[ v ].first;
		}
		for( auto val : adj[ v ] )
		{
			if( !selected[ val.first ] && edge[ val.first ].first > val.second )
			{
				edge[ val.first ] = { val.second, v };
			}
		}
	}
	cout << "Total Weight of the Minimum Spanning Tree: " << total << "\n";
	cout << "Edges are: " << "\n";
	for( auto val : ans )
	{
		cout << val.first << " " << val.second << "\n";
	}
	return 0;
}
