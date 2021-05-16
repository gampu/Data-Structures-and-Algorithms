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

// Calculate the maximum value that can be obtained by selecting non-adjacent nodes from a tree. Two nodes are adjacent if and only
// there exists a direct edge between them

int N = 1e5 + 5, n, a, b;
vector< int > dp1( N, 0 ), dp2( N, 0 ), value( N, 0 );
vector< vector< int > > adj( N );

void dfs( int u, int par )
{
    int res1 = 0, res2 = 0;
    for( int v : adj[ u ] )
    {
        if( v != par )
        {
            dfs( v, u );
            dp2[ u ] += dp1[ v ];
            res1 += dp1[ v ];
            res2 += dp2[ v ];
        }
    }
    dp1[ u ] = max( res1, value[ u ] + res2 );
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
    for( int i = 1; i <= n; ++i )
    {
        cin >> value[ i ];   
    }
    dfs( 1, -1 );
    cout << dp1[ 1 ] << "\n";
    return 0;
}
