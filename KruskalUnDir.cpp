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

// Kruskal's Algorithm
// Finds the minimum spanning tree of the undirected graph in the vector ans
// total is the sum of all weights of the edges of the minimum spanning tree

struct edge
{
	int s, e, w;
	bool operator< ( const struct edge& other )
	{
		return w < other.w;
	}
};
typedef struct edge Edge;

struct dsu
{
	vector< int > parent, size;

	void make_set( int v )
	{
		parent[ v ] = v;
		size[ v ] = 1;
	}

	int find_set( int v )
	{
		if( parent[ v ] == v )
		{
			return v;
		}
		return parent[ v ] = find_set( parent[ v ] );
	}

	bool unite_set( int a, int b )
	{
		a = find_set( a );
		b = find_set( b );
		if( a != b )
		{
			if( size[ a ] < size[ b ] )
			{
				swap( a, b );
			}
			parent[ b ] = a;
			size[ a ] += size[ b ];
			return true;
		}
		return false;
	}
};
typedef struct dsu DSU;

int N = 1e5 + 5, n, m, a, b, w, total = 0;
vector< Edge > edges, ans;
DSU work;
		
int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
		
	cin >> n >> m;
	work.parent.assign( n + 5, -1 );
	work.size.assign( n + 5, 0 );
	for( int i = 0; i <= n - 1; ++i ) 
	{
		work.make_set( i ); // vertices start from 0
	}
	for( int i = 0; i <= m - 1; ++i )
	{
		cin >> a >> b >> w; // 0 indexed 
		edges.push_back( { a, b, w } );
	}
	sort( edges.begin(), edges.end() );
	for( int i = 0; i <= edges.size() - 1 && ans.size() < n - 1; ++i )
	{
		a = edges[ i ].s;
		b = edges[ i ].e;
		w = edges[ i ].w;
		if( work.unite_set( a, b ) )
		{
			ans.push_back( { a, b, w } );
			total += w;
		}
	}
	cout << "Count: " << ans.size() << "\n";
	cout << "Total weight: " << total << "\n";
	cout << "Edges are: " << "\n";
	for( auto c : ans )
	{
		cout << c.s << " " << c.e << " " << c.w << "\n";
	}
	return 0;
}
