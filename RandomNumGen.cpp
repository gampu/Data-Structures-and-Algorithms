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

random_device rd;
mt19937 gen( rd() );
uniform_int_distribution<> dis( 1, 1000 );

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	for( int i = 1; i <= 10; ++i )
	{
		cout << dis( gen ) << "\n";
	}
	return 0;
}
