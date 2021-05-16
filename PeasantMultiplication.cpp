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

// Peasant Multiplication Algorithm

long long x, y;

long long mulitply( long long x, long long y )
{
	if( x == 0 )
	{
		return 0;
	}
	long long res = mulitply( x / 2, 2 * y );
	if( x & 1 )
	{
		res	+= y;
	}
	return res;
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> x >> y;
	cout << mulitply( x, y ) << "\n";	
	return 0;
}
