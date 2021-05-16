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

// https://cses.fi/problemset/task/1696/
// Max Bipartite Matching

int N, n, m, k, a, b, last;
set< int > s;
vector< int > matching( 1e3 + 3, -1 ), level( 1e3 + 3 ), par( 1e3 + 3 );
vector< pair< int, int > > ans;
vector< vector< int > > adj( 1e3 + 3 );

bool alternatingPath( void )
{
	while( s.size() )
	{
		fill( level.begin(), level.end(), -1 );
		fill( par.begin(), par.end(), -1 );
		queue< int > q;
		int v = *( s.begin() );
		s.erase( v );
		q.push( v );
		level[ v ] = 1;
		last = -1;
		while( !q.empty() )
		{
			v = q.front(); q.pop();
			for( int u : adj[ v ] )
			{
				if( level[ u ] == -1 && ( level[ v ] & 1 ) && matching[ u ] == -1 )
				{
					last = u;
					par[ u ] = v;
					return true;
				}
				else if( level[ u ] == -1 && ( level[ v ] & 1 ) && matching[ u ] != -1 )
				{
					par[ u ] = v;
					level[ u ] = level[ v ] + 1;
					q.push( u );
				}
				else if( level[ u ] == -1 && !( level[ v ] & 1 ) && matching[ u ] == v )
				{
					par[ u ] = v;
					level[ u ] = level[ v ] + 1;
					q.push( u );
				}
			}
		}
	}
	return false;
}
 
int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> m >> k;
	N = n + m;
	for( int i = 1; i <= N; ++i )
	{
		s.insert( i );		
	}
	for( int i = 1; i <= k; ++i )
	{
		cin >> a >> b;
		b += n;
		adj[ a ].emplace_back( b );
		adj[ b ].emplace_back( a );
	}
	while( alternatingPath() )
	{
		for( int u = last; u != -1; u = par[ par[ u ] ] )
		{
			s.erase( u );
			s.erase( par[ u ] );
			matching[ u ] = par[ u ];
			matching[ par[ u ] ] = u;
		}
	}
	for( int i = 1; i <= n; ++i )
	{
		if( matching[ i ] != -1 )
		{
			ans.emplace_back( i, matching[ i ] - n );
		}		
	}
	n = int( ans.size() );
	cout << n << "\n";
	for( int i = 1; i <= n; ++i )
	{
		cout << ans[ i - 1 ].first << " " << ans[ i - 1 ].second << "\n";
	}	
	return 0;
}
