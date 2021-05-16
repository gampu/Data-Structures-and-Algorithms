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

// Lowest Common Ancestor using Binary Lifting Algorithm

const int N = 1e5 + 5;
int n, l = 21, a, b, q; // l = 21 : Valid for elements until 1e6
vector< int > h( N, 0 );
vector< vector< int > > adj( N ), up( N, vector< int >( l, -1 ) );

void dfs( int u, int par )
{
	h[ u ] = 1 + h[ par ];
	up[ u ][ 0 ] = par;
	for( int v : adj[ u ] )
	{
		if( v != par )
		{	
			dfs( v, u );
		}
	}
}

int lca( int u, int v )
{
	if( h[ u ] < h[ v ] )
	{
		swap( u, v );
	}
	for( int i = l - 1; i >= 0; --i )
	{
		if( h[ u ] - h[ v ] >= ( 1 << i ) )
		{
			u = up[ u ][ i ];
		}
	}
	if( u == v )
	{
		return u;
	}
	for( int i = l - 1; i >= 0; --i )
	{
		if( up[ u ][ i ] != -1 && up[ v ][ i ] != -1 && up[ u ][ i ] != up[ v ][ i ] )
		{
			u = up[ u ][ i ];
			v = up[ v ][ i ];
		}
	}
	return up[ u ][ 0 ];
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 1; i <= n - 1; ++i )
	{
		cin >> a >> b; // 1-indexed
		adj[ a ].emplace_back( b );
		adj[ b ].emplace_back( a );
	}
	dfs( 1, 0 );
	for( int i = 1; i <= l - 1; ++i )
	{
		for( int j = 1; j <= n; ++j )
		{
			if( up[ j ][ i - 1 ] != -1 )
			{
				up[ j ][ i ] = up[ up[ j ][ i - 1 ] ][ i - 1 ];
			}
		}
	}
	cin >> q;
	for( int i = 1; i <= q; ++i )
	{
		cin >> a >> b;
		cout << lca( a, b ) << "\n";
	}
	return 0;
}
