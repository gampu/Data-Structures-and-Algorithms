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

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	bool ans = true;
	int n, m, u, v;
	cin >> n >> m;
	vector< vector< int > > adj( n );
	for( int i = 1; i <= m; ++i )
	{
		cin >> u >> v;
		adj[ u ].emplace_back( v );
		adj[ v ].emplace_back( u );
	}
	vector< int > side( n, -1 );
	queue< int > q;
	for( int i = 0; i <= n - 1 and ans; ++i )
	{
		if( side[ i ] == -1 )
		{
			q.push( i );
			side[ i ] = 0;
			while( !q.empty() )
			{
				v = q.front();
				q.pop();
				for( int u : adj[ v ] )
				{
					if( side[ u ] == -1 )
					{
						side[ u ] = !side[ v ];
						q.push( u );
					}
					else if( side[ u ] == side[ v ] )
					{
						ans = false;
						break;
					}
				}
			}
		}
	}
	if( ans )
	{
		cout << "Yes. The input graph is a bipartite graph" << endl;
		vector< int > side1, side2;
		for( int i = 0; i <= n - 1; ++i )
		{
			if( side[ i ] == 0 )
			{
				side1.emplace_back( i );
			}
			else
			{
				side2.emplace_back( i );
			}		
		}
		cout << "Side 0 is: ";
		for( int c : side1 )
		{
			cout << c << " ";
		}
		cout << endl;
		cout << "Side 1 is: ";
		for( int c : side2 )
		{
			cout << c << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "No. The input graph is not a bipartite graph" << endl;
	}
	return 0;
}
/*
7 5
0 3
0 5
1 4
2 4
2 6
Yes. The input graph is a bipartite graph
Side 0 is: 0 1 2 
Side 1 is: 3 4 5 6

7 6
0 3
0 5
1 4
2 4
2 6
4 6
No. The input graph is not a bipartite graph

*/
