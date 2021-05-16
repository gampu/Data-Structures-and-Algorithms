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

// Prufer code to tree
// https://cses.fi/problemset/task/1134/
// n is number of vertices

int n, leaf;
set< int > s;
vector< int > prufer( 2e5 + 5 ), deg( 2e5 + 5, 1 );

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 1; i <= n - 2; ++i )
	{
		cin >> prufer[ i ];
		++deg[ prufer[ i ] ];
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
		cout << leaf << " " << prufer[ i ] << "\n";
		--deg[ prufer[ i ] ];
		if( deg[ prufer[ i ] ] == 1 )
		{
			s.insert( prufer[ i ] );
		}
	}
	cout << *( s.begin() ) << " " << *( s.rbegin() ) << "\n";
	return 0;
}
