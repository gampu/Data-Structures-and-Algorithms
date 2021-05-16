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

long double l = 1.0, r = 2.0, mid;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	while( r - l >= 1e-18 ) // This condition achieves the precision required
	{
		mid = ( l + r ) / 2;
		if( mid * mid < 2 )
		{
			l = mid;
		}
		else if( mid * mid > 2 )
		{
			r = mid;
		}
	}
	cout << fixed << setprecision( 2000 ) << l << "\n";
	return 0;
}
