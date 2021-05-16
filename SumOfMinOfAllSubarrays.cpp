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

// Sum of minimum of all subarrays in O( n ) time

const int N = 1e5 + 5;
int n;
long long int ans = 0;
vector< int > arr( N ), pos( N, 0 ), dp( N, 0 );
stack< int > st;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		cin >> arr[ i ];
	}
	pos[ n ] = n + 1;
	st.push( n );
	for( int i = n - 1; i >= 1; --i )
	{
		while( !st.empty() && arr[ st.top() ] > arr[ i ] )
		{
			st.pop();
		}
		if( st.empty() )
		{
			pos[ i ] = n + 1;
		}
		else
		{
			 pos[ i ] = st.top();
		}
		st.push( i );
	}
	for( int i = n; i >= 1; --i )
	{
		dp[ i ] = ( pos[ i ] - i ) * arr[ i ] + dp[ pos[ i ] ];
		ans += dp[ i ];
	}
	cout << ans << "\n";
	return 0;
}
// https://leetcode.com/problems/sum-of-subarray-minimums/submissions/
