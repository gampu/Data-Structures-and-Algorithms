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

// Dynamic Programming on Trees: In-Out DP
// Find the height of the tree when it is rooted at node i: 1 <= i <= n.

const int N = 1e5 + 5;
int n, a, b, res;
vector< int > in( N, 0 ), out( N, 0 );
vector< vector< int > > adj( N );
vector< pair< int, int > > mx( N, { -1, -1 } );

void dfsin( int u, int par )
{
	for( int v : adj[ u ] )
	{	
		if( v != par )
		{
			dfsin( v, u );
			if( in[ v ] > mx[ u ].first )
			{
				mx[ u ].second = mx[ u ].first;
				mx[ u ].first = in[ v ];
			}
			else if( in[ v ] > mx[ u ].second )
			{
				mx[ u ].second = in[ v ];
			}
			in[ u ] = max( in[ u ], 1 + in[ v ] );
		}
	}
}

void dfsout( int u, int par )
{
	res = mx[ par ].first;
	if( in[ u ] == res )
	{
		res = mx[ par ].second;
	}
	if( u != 1 )
	{
		out[ u ] = max( 1 + out[ par ], 2 + res );
	}
	for( int v : adj[ u ] )
	{
		if( v != par )
		{
			dfsout( v, u );
		}
	}
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
	dfsin( 1, 0 );
	dfsout( 1, 0 );
	for( int i = 1; i <= n; ++i )
	{
		cout << max( in[ i ], out[ i ] ) << " ";
	}
	cout << "\n";
	return 0;
}
/*
10
1 2
1 3
1 4
2 5
2 6
3 7
4 8
7 9
7 10
3 4 3 4 5 5 4 5 5 5
*/
// Yet another similar way

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

// https://cses.fi/problemset/task/1132/

const int N = 2e5 + 5;
int n, a, b;
vector< int > dpin( N, 0 ), dpout( N, -1 );
vector< vector< int > > adj( N );
vector< vector< int > > mx( N, vector< int >{ -3, -2 } );

void dfsin( int u, int par )
{
	for( int v : adj[ u ] )
	{
		if( v != par )
		{
			dfsin( v, u );
			dpin[ u ] = max( dpin[ u ], 1 + dpin[ v ] );
		}
	}
	if( dpin[ u ] >= mx[ par ][ 1 ] )
	{
		mx[ par ][ 0 ] = mx[ par ][ 1 ];
		mx[ par ][ 1 ] = dpin[ u ];
	}
	else if( dpin[ u ] > mx[ par ][ 0 ] )
	{
		mx[ par ][ 0 ] = dpin[ u ];
	}
}

void dfsout( int u, int par )
{
	dpout[ u ] = max( 1 + dpout[ par ], 2 + ( mx[ par ][ 1 ] == dpin[ u ] ? mx[ par ][ 0 ] : mx[ par ][ 1 ] ) );
	for( int v : adj[ u ] )
	{
		if( v != par )
		{
			dfsout( v, u );
		}
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 1; i <= n - 1; ++i )
	{
		cin >> a >> b;
		adj[ a ].emplace_back( b );
		adj[ b ].emplace_back( a );
	}
	dfsin( 1, 0 );
	dfsout( 1, 0 );
	for( int i = 1; i <= n; ++i )
	{
		cout << max( dpin[ i ], dpout[ i ] ) << " \n"[ i == n ];		
	}
	return 0;
}
