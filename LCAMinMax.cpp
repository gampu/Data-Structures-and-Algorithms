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

// https://www.spoj.com/problems/DISQUERY/
// For each of the q given pairs of cities, find the length of the shortest and the length of the longest road on the path
// between the two cities.

struct node
{
	int mn;
	int mx;
};
typedef struct node Node;

const int N = 1e5 + 5;
int n, l = 21, a, b, c, q;
vector< int > h( N, 0 );
vector< vector< pair< int, int > > > adj( N );
vector< vector< int > > up( N, vector< int >( l, -1 ) );
vector< vector< Node > > dp( N, vector< Node >( l ) );

void dfs( int u, int par, int d )
{
	h[ u ] = 1 + h[ par ];
	up[ u ][ 0 ] = par;
	dp[ u ][ 0 ] = { d, d };
	for( auto v : adj[ u ] )
	{
		if( v.first != par )
		{	
			dfs( v.first, u, v.second );
		}
	}
}

Node lca( int u, int v )
{
	Node ans = { 10000000, -1 };
	if( h[ u ] < h[ v ] )
	{
		swap( u, v );
	}
	for( int i = l - 1; i >= 0; --i )
	{
		if( h[ u ] - h[ v ] >= ( 1 << i ) )
		{
			ans.mn = min( ans.mn, dp[ u ][ i ].mn );	ans.mx = max( ans.mx, dp[ u ][ i ].mx );
			u = up[ u ][ i ];
		}
	}
	if( u == v )
	{
		return ans;
	}
	for( int i = l - 1; i >= 0; --i )
	{
		if( up[ u ][ i ] != -1 && up[ v ][ i ] != -1 && up[ u ][ i ] != up[ v ][ i ] )
		{
			ans.mn = min( ans.mn, dp[ u ][ i ].mn );	ans.mx = max( ans.mx, dp[ u ][ i ].mx );
			ans.mn = min( ans.mn, dp[ v ][ i ].mn );	ans.mx = max( ans.mx, dp[ v ][ i ].mx );
			u = up[ u ][ i ];
			v = up[ v ][ i ];
		}
	}
	ans.mn = min( ans.mn, dp[ u ][ 0 ].mn );	ans.mx = max( ans.mx, dp[ u ][ 0 ].mx );
	ans.mn = min( ans.mn, dp[ v ][ 0 ].mn );	ans.mx = max( ans.mx, dp[ v ][ 0 ].mx );
	return ans;
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 1; i <= n - 1; ++i )
	{
		cin >> a >> b >> c;
		adj[ a ].emplace_back( b, c );
		adj[ b ].emplace_back( a, c );
	}
	dfs( 1, 0, 0 );
	for( int i = 1; i <= l - 1; ++i )
	{
		for( int j = 1; j <= n; ++j )
		{
			if( up[ j ][ i - 1 ] != -1 )
			{
				up[ j ][ i ] = up[ up[ j ][ i - 1 ] ][ i - 1 ];
				int v = up[ j ][ i - 1 ];
				dp[ j ][ i ] = { min( dp[ j ][ i - 1 ].mn, dp[ v ][ i - 1 ].mn ), max( dp[ j ][ i - 1 ].mx, dp[ v ][ i - 1 ].mx ) };
			}
		}
	}
	cin >> q;
	for( int i = 1; i <= q; ++i )
	{
		cin >> a >> b;
		Node res = lca( a, b );
		cout << res.mn << " " << res.mx << "\n";
	}
	return 0;
}
