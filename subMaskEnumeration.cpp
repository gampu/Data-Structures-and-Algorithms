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

int main( void )
{
	int n, cnt = 0; // for counting numbers that get output on the screen
	cin >> n;	
	for( int m = 0; m <= ( 1 << n ) - 1; ++m ) // For more insights, see notes; O( 3 ^ n )
	{
		for( int s = m; s > 0; s = ( s - 1 ) & m )
		{
			++cnt;
			cout << s << endl;
		}	
	}
	cout << cnt << endl;
	return 0;
}
