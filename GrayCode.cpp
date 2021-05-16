#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<utility>
#include<functional>
#include<bitset>
#include<cstring>
using namespace std;

//Gray Code

int g( int n )
{
	return ( n ^ ( n >> 1 ) ); //Understood
}

int rev( int g )
{
	int n = 0;
	for( ; g > 0; g >>= 1 ) //Understood
	{
		n ^= g;
	}
	return n;
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	int n;
	cin >> n;
	for( int i = 0; i <= n; ++i )
	{
		int ans = g( i );
		cout << i << " " << ans << " " << rev( ans ) << "\n";
	}
	return 0;
}
