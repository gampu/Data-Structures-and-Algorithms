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
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	int n;
	cin >> n;
	vector< int > ans;
	for( int subset = 0; subset <= ( 1 << n ) - 1; ++subset )
	{
		ans.clear();
		int sum = 0, mask = 1;
		for( int i = 0; i <= n - 1; ++i )
		{
			if( ( subset & mask ) == mask )
			{
				ans.emplace_back( i + 1 ); // Saved positions.
			}
			mask <<= 1;
		}
		for( int c : ans )
		{	
			cout << c << " "; // Empty means zero
		}
		cout << endl;
	}
	return 0;
}
