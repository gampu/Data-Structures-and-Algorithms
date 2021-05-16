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

struct edge
{
	long long cap = 0;
	long long flow = 0;
};
typedef struct edge Edge;

class Dinic
{
public:
	int N, n, m, s, t, u, v, dir;
	long long ans;
	vector< vector< Edge > > am;
	vector< vector< pair< int, int > > > adj;
	vector< pair< int, int > > par;
	vector< long long > label;
	vector< int > vis, level, ptr, st;
	
	void set( int nodes, int edges, int src, int term )
	{
		n = nodes, m = edges, s = src, t = term;
		N = n + 5;
		am.resize( N, vector< Edge >( N ) );
		adj.resize( N );
		par.resize( N );
		vis.resize( N );
		label.resize( N );
		level.resize( N );
		ptr.resize( N );
		ans = 0;
		par[ s ] = { 0, 0 };
		label[ s ] = 1e18;
	}

	void addEdge( int a, int b, int c )
	{
		if( a == b )
		{
			return; // Loops
		}
		if( am[ a ][ b ].cap == 0 )
		{
			am[ a ][ b ] = { c, 0 };
			adj[ a ].emplace_back( b, 1 );
			adj[ b ].emplace_back( a, -1 );
		}
		else
		{
			am[ a ][ b ].cap += c; // Multiple edges between a and b
		}
	}

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
				if( am[ v ][ u ].flow == am[ v ][ u ].cap )
				{
					++ptr[ v ];
				}
			}
			else
			{
				am[ u ][ v ].flow -= label[ t ];
				if( am[ v ][ u ].flow == 0 )
				{
					++ptr[ v ];
				}
			}
			u = v;
		}while( u != 0 );
	}

	bool layerNetwork( void )
	{
		fill( ptr.begin(), ptr.end(), 0 );
		fill( level.begin(), level.end(), 0 );
		queue< int > q;
		q.push( s );
		level[ s ] = 1;
		while( !q.empty() )
		{
			v = q.front();	q.pop();
			for( auto edge : adj[ v ] )
			{
				u = edge.first;	dir = edge.second;
				if( level[ u ] == 0 )
				{
					if( dir == 1 && am[ v ][ u ].cap - am[ v ][ u ].flow > 0 )
					{
						level[ u ] = level[ v ] + 1;
						q.push( u );
					}
					else if( dir == -1 && am[ u ][ v ].flow > 0 )
					{
						level[ u ] = level[ v ] + 1;
						q.push( u );
					}
					if( u == t && level[ u ] != 0 )
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	long long solve( void )
	{
		while( layerNetwork() )
		{
			fill( vis.begin(), vis.end(), 0 );
			vis[ s ] = 1;
			st = { s };
			while( st.size() > 0 )
			{
				v = st.back();
				for( int& i = ptr[ v ]; i <= ( int )adj[ v ].size() - 1; ++i )
				{
					auto edge = adj[ v ][ i ];
					u = edge.first;	dir = edge.second;
					if( !vis[ u ] && level[ u ] == level[ v ] + 1 )
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
							st.emplace_back( u );
							if( u == t )
							{
								augment();
								fill( vis.begin(), vis.end(), 0 );
								vis[ s ] = 1;
								st = { s };
							}
							break;
						}
					}
				}
				if( ptr[ v ] == adj[ v ].size() )
				{	
					st.pop_back();
					if( st.size() > 0 )
					{	
						++ptr[ st.back() ];
					}
				}
			}
		}
		return ans;
	}

	vector< pair< int, int > > minCut( void )
	{
		vector< pair< int, int > > res;
		for( int v = 1; v <= n; ++v )
		{
			for( auto edge : adj[ v ] )
			{
				u = edge.first;	dir = edge.second;
				if( dir == 1 )
				{
					if( level[ v ] && !level[ u ] )
					{
						res.emplace_back( v, u );
					}
				}
			}
		}
		return res;
	}
};

Dinic dinic;
int n, m, s, t, a, b, c;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> m;
	s = 1, t = n;
	dinic.set( n, m, s, t );
	for( int i = 1; i <= m; ++i )
	{
		cin >> a >> b >> c;
		dinic.addEdge( a, b, c );
	}
	cout << dinic.solve() << "\n";
	return 0;
}
