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

// Tree to prufer code

int n, a, b, leaf, par;
set< int > s;
vector< int > deg( 2e5 + 5, 0 ), ans;
vector< set< int > > adj( 2e5 + 5 );

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 1; i <= n - 1; ++i )
	{
		cin >> a >> b;
		adj[ a ].insert( b );
		adj[ b ].insert( a );
		++deg[ a ];
		++deg[ b ];
	}
	for( int i = 1; i <= n; ++i )
	{
		if( deg[ i ] == 1 )
		{
			s.insert( i );
		}		
	}
	for( int i = 1; i <= n - 2; ++i )
	{
		leaf = *( s.begin() );
		s.erase( leaf );
		par = *( adj[ leaf ].begin() );
		adj[ par ].erase( leaf );
		ans.emplace_back( par );
		--deg[ par ];
		if( deg[ par ] == 1 )
		{
			s.insert( par );
		}
	}
	for( int i = 1; i <= n - 2; ++i )
	{
		cout << ans[ i - 1 ] << " \n"[ i == n - 2 ];
	}
	return 0;
}
