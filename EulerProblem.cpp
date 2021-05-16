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

int N = 90000;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	for( int a = 1; a <= N / 3 - 1; ++a )
	{
		for( int b = a + 1; b <= ( N - a ) / 2 - 1; ++b )
		{
			int c = N - a - b;
			if( a * a + b * b == c * c )
			{
				cout << a << " " << b << " " << c << "\n";
			}
		}
	}
	return 0;
}
