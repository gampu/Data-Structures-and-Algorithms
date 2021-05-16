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

// Euler path for an undirected graph
// Assumes that an euler path exists i.e. every vertex except two of the input graph has an even degree and the graph is connected
// Modification of Hierholzer's Algorithm

int N = 1010, n, m, a, b;
vector< vector< int > > adj( N );
vector< vector< bool > > marked( N, vector< bool >( N, false ) ); // whether edge ( u, v ) or ( v, u ) has been used
vector< int > dp( N, 0 ), deg( N, 0 ), ans, odd;
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
		++deg[ a ];
		++deg[ b ];
		adj[ a ].emplace_back( b );
		adj[ b ].emplace_back( a );
	}
	for( int v = 0; v <= n - 1; ++v )
	{
		if( deg[ v ] & 1 )
		{
			odd.emplace_back( v );
		}
	}
	if( odd.size() != 2 )
	{
		cout << -1 << "\n";
		return 0;
	}
	a = odd[ 0 ]; 
	b = odd[ 1 ];
	adj[ a ].emplace_back( b );
	swap( adj[ a ][ 0 ], adj[ a ][ adj[ a ].size() - 1 ] );
	adj[ b ].emplace_back( a );
	swap( adj[ b ][ 0 ], adj[ b ][ adj[ b ].size() - 1 ] );
	st.push( a );
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
	if( s.size() != n and ans.size() != m + 2 )
	{
		cout << s.size() << " " << ans.size() << "\n";
		cout << -1 << "\n";
		return 0;
	}
	cout << "Euler path is: " << "\n";
	for( int v = 0; v <= ans.size() - 2; ++v )
	{
		cout << ans[ v ] << " ";
	}
	cout << "\n";
	return 0;
}
/*
Removing each edge from the example of euler tour and providing as input for euler path
7 7
1 2
2 5 
5 1
1 4
4 2
2 3
3 0
Euler path is: 
0 3 2 4 1 2 5 1 

7 7
0 1
2 5 
5 1
1 4
4 2
2 3
3 0
Euler path is: 
1 0 3 2 5 1 4 2 

7 7
0 1
1 2
5 1
1 4
4 2
2 3
3 0
Euler path is: 
2 1 4 2 3 0 1 5

7 7
0 1
1 2
2 5
1 4
4 2
2 3
3 0
Euler path is: 
1 0 3 2 4 1 2 5

7 7
0 1
1 2
2 5
5 1
4 2
2 3
3 0
Euler path is: 
1 0 3 2 5 1 2 4 

7 7
0 1
1 2
2 5
5 1
1 4
2 3
3 0
Euler path is: 
2 1 5 2 3 0 1 4

7 7
0 1
1 2
2 5
5 1
1 4
2 4
3 0
Euler path is: 
2 4 1 5 2 1 0 3

7 7
0 1
1 2
2 5
5 1
1 4
2 4
3 2
Euler path is: 
0 1 4 2 5 1 2 3

*/
