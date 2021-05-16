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

int n, l, r, cnt = 0, ans = 0;
vector< pair< int, int > > arr;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		cin >> l >> r;
		arr.emplace_back( l, 0 );
		arr.emplace_back( r, 1 );		
	}
	sort( arr.begin(), arr.end() );
	for( auto pos : arr )
	{
		if( pos.second == 0 )
		{
			++cnt;
		}
		else
		{
			--cnt;
		}
		ans = max( ans, cnt );
	}
	cout << ans << "\n";
	return 0;
}
