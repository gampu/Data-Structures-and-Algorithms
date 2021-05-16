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

// solves a quadratic equation in general. Outputs the number of distinct roots followed by the roots in ascending order.

long long int a, b, c, d;

int main( void )
{
	ios :: sync_with_stdio( false );
	cin.tie( 0 );
	
	cout << setprecision( 15 ) << fixed;

	cin >> a >> b >> c;
	d = b * b - 4 * a * c;
	if( a == 0 and b == 0 and c == 0 )
	{
		cout << -1 << endl;
	}
	else if( ( a == 0 and b == 0 ) or d < 0 )
	{
		cout << 0 << endl;
	}
	else if( a == 0 and b != 0 )
	{
		cout << 1 << endl;
		cout << ( double )-c / b << endl;
	}
	else
	{
		if( d == 0 )
		{
			cout << 1 << endl;
			cout << ( double )-b / ( 2 * a ) << endl;
		}
		else
		{
			cout << 2 << endl;
			double ans1 = ( -b + sqrt( d ) ) / ( 2 * a );
			double ans2 = ( -b - sqrt( d ) ) / ( 2 * a );
			if( ans1 < ans2 )
			{
				cout << ans1 << endl << ans2 << endl;
			}
			else
			{
				cout << ans2 << endl << ans1 << endl;
			}
		}
	}	
	return 0;
}
// https://codeforces.com/contest/20/problem/B
