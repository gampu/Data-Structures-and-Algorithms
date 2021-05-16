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

// Edmond's Karp BFS Implementation of Max-Flow Algorithm by Ford-Fulkerson

struct edge
{
	int cap;
	int flow;
};
typedef struct edge Edge;

const int N = 1e3 + 3;
int n, m, a, b, c, s, t, u, v, dir, ans = 0;
vector< vector< Edge > > am( N, vector< Edge >( N ) );
vector< vector< pair< int, int > > > adj( N );
vector< pair< int, int > > par( N );
vector< int > vis( N, 0 ), label( N );
queue< int > q;

void augment( void )
{	
	ans += label[ t ];
	u = t;
	do
	{
		v = par[ u ].first;	dir = par[ u ].second;
		if( dir == 1 )
		{
			am[ v ][ u ].flow += label[ t ];
		}
		else
		{
			am[ u ][ v ].flow -= label[ t ];
		}
		u = v;
	}while( u != 0 );
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> m >> s >> t;
	for( int i = 1; i <= m; ++i )
	{
		cin >> a >> b >> c;
		am[ a ][ b ] = { c, 0 };
		adj[ a ].emplace_back( b, 1 );
		adj[ b ].emplace_back( a, -1 );
	}
	par[ s ] = { 0, 0 };
	label[ s ] = 1e9;
	vis[ s ] = 1;
	q.push( s );
	while( !q.empty() )
	{
		v = q.front();	q.pop();
		for( auto edge : adj[ v ] )
		{
			u = edge.first;	dir = edge.second;
			if( !vis[ u ] )
			{
				if( dir == 1 && am[ v ][ u ].cap - am[ v ][ u ].flow > 0 )
				{
					label[ u ] = min( label[ v ], am[ v ][ u ].cap - am[ v ][ u ].flow );
					par[ u ] = { v, 1 };
					vis[ u ] = 1;
				}
				else if( dir == -1 && am[ u ][ v ].flow > 0 )
				{
					label[ u ] = min( label[ v ], am[ u ][ v ].flow );
					par[ u ] = { v, -1 };
					vis[ u ] = 1;
				}
				if( vis[ u ] )
				{
					q.push( u );
					if( u == t )
					{
						augment();
						fill( vis.begin(), vis.end(), 0 );
						label[ s ] = 1e9;
						vis[ s ] = 1;
						q = queue< int >();
						q.push( s );
						break;
					}
				}
			}
		}
	}
	cout << ans << "\n"; // Value of Max Flow
	for( int i = 1; i <= n; ++i )
	{
		if( vis[ i ] )
		{
			cout << i << " "; // Vertices in set X.
		}		
	}
	cout << "\n";
	for( v = 1; v <= n; ++v ) // Outputs Min Cut
	{
		for( auto edge : adj[ v ] )
		{
			u = edge.first;	dir = edge.second;
			if( dir == 1 )
			{
				if( vis[ v ] && !vis[ u ] )
				{
					cout << "From X to X` " << v << " " << u << " " << am[ v ][ u ].cap << " " << am[ v ][ u ].flow << "\n";
				}
				else if( !vis[ v ] && vis[ u ] )
				{
					cout << "From X` to X " << v << " " << u << " " << am[ v ][ u ].cap << " " << am[ v ][ u ].flow << "\n";
				}
			}
		}
	}
	return 0;
}
/*
Example 1: 
8 12 1 8
1 2 2
1 3 4
1 4 1
3 2 2
2 5 5
3 7 3
4 6 2 
4 7 3
6 5 5 
5 8 3 
6 8 2 
7 8 1

5
1 2 3 5 7 
From X to X` 1 4 1 1
From X` to X 4 7 3 0
From X to X` 5 8 3 3
From X` to X 6 5 5 0
From X to X` 7 8 1 1


Example 2:
4 5 1 4
1 2 10
1 3 10
2 3 1
2 4 10
3 4 10
20
1 
From X to X` 1 2 10 10
From X to X` 1 3 10 10
*/
