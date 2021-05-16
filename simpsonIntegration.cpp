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
using namespace std;

int N = 1000 * 1000;
long double s, a, b, h, x;

long double f( long double arg )
{
	return 1 / expl( arg );
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> a >> b;
	h = ( b - a ) / N;
	s = f( a ) + f( b );
	for( int i = 1; i <= N - 1; ++i )
	{
		x = a + i * h;
		s += f( x ) * ( ( i & 1 ) ? 4 : 2 );
	}
	s *= h / 3;
	cout << fixed << setprecision( 20 ) << s << endl;
	return 0;
}
