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

// For each node u, count the size of the subtree rooted at u

int n, a, b, cnt = 0;
vector< int > ans( 1e5 + 5 ), pos( 1e5 + 5 );
vector< vector< int > > adj( 1e5 + 5 );
vector< set< int > > sets( 1e5 + 5 );

void dfs( int par, int u )
{
	int children = 0, mx = 0, ch;
	for( int v : adj[ u ] )
	{
		if( v != par )
		{
			++children;
			dfs( u, v );
			if( sets[ pos[ v ] ].size() > mx )
			{
				mx = sets[ pos[ v ] ].size();
				ch = v;
			}
		}
	}
	if( !children )
	{
		++cnt;
		sets[ cnt ].insert( u );
		ans[ u ] = 1;
		pos[ u ] = cnt;
	}
	else
	{
		for( int v : adj[ u ] )
		{
			if( v != par && v != ch )
			{
				sets[ pos[ ch ] ].insert( sets[ pos[ v ] ].begin(), sets[ pos[ v ] ].end() );
				sets[ pos[ v ] ].clear();
			}
		}
		sets[ pos[ ch ] ].insert( u );
		pos[ u ] = pos[ ch ];
		ans[ u ] = sets[ pos[ ch ] ].size();
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
	dfs( 0, 1 );
	for( int i = 1; i <= n; ++i )
	{
		cout << ans[ i ] << "\n";		
	}
	return 0;
}
