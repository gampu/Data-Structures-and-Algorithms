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

// Explore the behaviour of the problem pattern for primes and non-primes.
// Find the value of d < 1000 for which 1 / d contains the longest recurring cycle in its decimal fraction part.
// https://projecteuler.net/problem=26

int ans = 0, pos, a, ok;
vector< int > vis( 1010 );

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	for( int d = 1; d <= 999; ++d )
	{
		pos = 1;
		a = 1;
		ok = 1;
		fill( vis.begin(), vis.end(), -1 );
		while( ok )
		{
			a *= 10;
			a %= d;
			if( vis[ a ] == -1 )
			{
				vis[ a ] = pos;
			}
			else
			{
				ans = max( ans, pos - vis[ a ] ); // modify to store the value of d
				ok = 0;
			}
			if( a == 0 )
			{
				ok = 0;
			}
			++pos;
		}
	}
	cout << ans << "\n"; // ans is the length of the longest recurring cycle in its decimal fraction part.
	return 0;
}
