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

//You are given number of nodes, N, and number of edges, M, of a undirected connected graph. After adding each edge, print the
// size of all the connected components (in increasing order).

int n, m, a, b;
multiset< int > ans; // our intended answer variable
vector< int > parent( 1e3 + 3, -1 ), size( 1e3 + 3, 0 );
vector< vector< int > > sets( 1e3 + 3 );

void make_set( int v )
{
	parent[ v ] = v;
	size[ v ] = 1;
	sets[ v ].emplace_back( v );
	ans.insert( size[ v ] );
}

int find_set( int v )
{
	return parent[ v ];
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
		while( !sets[ b ].empty() )
		{
			int v = sets[ b ].back();
			sets[ b ].pop_back();
			sets[ a ].emplace_back( v );
			parent[ v ] = a;
		}
		ans.erase( ans.find( size[ a ] ) );
		ans.erase( ans.find( size[ b ] ) );
		size[ a ] += size[ b ];
		size[ b ] = 0;
		ans.insert( size[ a ] );
		return true;
	}
	return false;
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> m;
	for( int i = 1; i <= n; ++i )
	{
		make_set( i );
	}
	for( int i = 1; i <= m; ++i )
	{
		cin >> a >> b;
		unite_set( a, b );
		for( int val : ans )
		{
			cout << val << " ";
		}
		cout << "\n";
	}
	return 0;
}
