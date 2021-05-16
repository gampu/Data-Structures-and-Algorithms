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

// 0-1 BFS

const int N = 1e5 + 5;
int n, m, a, b, w, v, start = 1;
vector< vector< pair< int, int > > > adj( N );
vector< int > dist( N, 1e9 ), pred( N, -1 ), present( N, 1 );
deque< pair< int, int > > q;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> m;
	for( int i = 1; i <= m; ++i )
	{
		cin >> a >> b >> w;
		++a; // convert to 1-indexed
		++b;
		adj[ a ].push_back( { b, w } );
	}
	dist[ start ] = 0; // Let's find shortest paths from vertex 1 to all other vertices
	q.push_back( { dist[ start ], 1 } );
	while( !q.empty() )
	{
		auto val = q.front(); q.pop_front();
		v = val.second;
		if( val.first != dist[ v ] )
		{
			continue;
		}
		present[ v ] = 0;
		for( auto e : adj[ v ] )
		{
			if( present[ e.first ] && dist[ e.first ] > dist[ v ] + e.second )
			{
				dist[ e.first ] = dist[ v ] + e.second;
				pred[ e.first ] = v;
				if( e.second == 0 )
				{
					q.push_front( { dist[ e.first ], e.first } );
				}
				else
				{
					q.push_back( { dist[ e.first ], e.first } );
				}
			} 
		}
	}
	for( int i = 1; i <= n; ++i )
	{
		cout << "From " << start << " to " << i << ": " << dist[ i ] << "\n";
		cout << "Path is: ";
		if( dist[ i ] != 1e9 )
		{
			int j = i;
			cout << j << " ";
			while( j != start )
			{
				j = pred[ j ];
				cout << j << " ";
			}
		}
		else
		{
			cout << "Does not Exist";
		}
		cout << "\n" << "\n";
	}
	return 0;
}
/*
5 7
0 1 1 
0 3 0
1 2 1 
1 3 1 
1 4 0
3 4 1 
2 4 0
*/
