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

// Euler tour for an undirected graph
// Assumes that an euler tour exists i.e. every vertex of the input graph has an even degree and the graph is connected
// Hierholzer's Algorithm
// Euler tour isn't unique i.e there may exist one or more euler tours

int N = 1010, n, m, a, b;
vector< vector< int > > adj( N );
vector< vector< bool > > marked( N, vector< bool >( N, false ) ); // whether edge ( u, v ) or ( v, u ) has been used
vector< int > dp( N, 0 ), ans;
stack< int > st;
set< int > s;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> m;
	for( int i = 1; i <= m; ++i )
	{
		cin >> a >> b;
		adj[ a ].emplace_back( b );
		adj[ b ].emplace_back( a );
	}
	st.push( 0 );
	while( !st.empty() )
	{
		int v = st.top();
		if( dp[ v ] == adj[ v ].size() )
		{
			ans.emplace_back( v );
			s.insert( v );
			st.pop();
		}
		else
		{
			int& i = dp[ v ]; // dp[ v ] is the next vertex to be processed
			for( ; i <= adj[ v ].size() - 1; ++i )
			{
				int u = adj[ v ][ i ];
				if( !marked[ v ][ u ] && !marked[ u ][ v ] )
				{
					st.push( u ); // start another cycle
					++i;
					marked[ v ][ u ] = 1; marked[ u ][ v ] = 1;
					break;
				}
			}
		}
	}
	if( s.size() != n and ans.size() != m + 1 )
	{
		cout << -1 << "\n";
		return 0;
	}
	cout << "Euler tour is: " << "\n";
	for( int v : ans )
	{
		cout << v << " ";
	}
	cout << "\n";
	return 0;
}
/*
7 8
0 1
1 2
2 5 
5 1
1 4
4 2
2 3
3 0
Euler tour is: 
0 3 2 4 1 5 2 1 0

7 8
5 1
4 2
1 4
1 2
2 3
0 1
3 0
2 5
Euler tour is: 
0 3 2 1 4 2 5 1 0
*/
