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

// https://cses.fi/problemset/task/1130/
// https://www.spoj.com/problems/PT07X/
// Minimum vertex cover of a tree
// dp1[ i ] is the answer when you consider ith vertex
// dp2[ i ] is the answer when you don't consider ith vertex

int N = 2e5 + 5, n, a, b;
vector< int > dp1( N, 1 ), dp2( N, 0 );
vector< vector< int > > adj( N );

void dfs( int u, int par )
{
	for( int v : adj[ u ] )
	{
		if( v != par )
		{
			dfs( v, u );
			dp1[ u ] += min( dp1[ v ], dp2[ v ] ); // When you consider u, take the answer of all its children
			dp2[ u ] += dp1[ v ]; // When you don't consider u, you have to take all its children
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
    dfs( 1, 0 );
    cout << min( dp1[ 1 ], dp2[ 1 ] ) << "\n";
    return 0;
}
