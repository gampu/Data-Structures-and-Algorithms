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

// https://codeforces.com/problemset/problem/20/C

int n, m, a, b, w, v, start = 1;
vector< long long > dist( 1e5 + 5, 1e18 );
vector< int > present( 1e5 + 5, 1 ), pred( 1e5 + 5, 0 ), ans;
set< pair< long long, int > > s;
vector< vector< pair< int, int > > > adj( 1e5 + 5 );

int main( void )
{	
	cin >> n >> m;
	for( int i = 1; i <= m; ++i )
	{
		cin >> a >> b >> w;
		adj[ a ].emplace_back( b, w );
		adj[ b ].emplace_back( a, w );
	}
	dist[ start ] = 0;
	for( int i = 1; i <= n; ++i )
	{
		s.insert( { dist[ i ], i } );
	}
	while( !s.empty() )
	{
		auto c = *( s.begin() );
		s.erase( c );
		v = c.second;
		present[ v ] = 0;
		for( auto e : adj[ v ] )
		{
			if( present[ e.first ] && dist[ e.first ] > dist[ v ] + e.second )
			{
				s.erase( { dist[ e.first ], e.first } );
				dist[ e.first ] = dist[ v ] + e.second;
				pred[ e.first ] = v;
				s.insert( { dist[ e.first ], e.first } );
			}
		}
	}
	if( dist[ n ] == 1e18 )
	{
		cout << -1 << "\n";
		return 0;
	}
	v = n;
	while( v != 0 )
	{
		ans.emplace_back( v );
		v = pred[ v ];
	}
	reverse( ans.begin(), ans.end() );
	n = ans.size();
	for( int i = 0; i <= n - 1; ++i )
	{
		cout << ans[ i ] << " \n"[ i == n - 1 ];
	}
	return 0;
}
