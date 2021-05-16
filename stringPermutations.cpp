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
using namespace std;

string str, ans;
int n, cnt = 0;

void backtrack( int pos, multiset< char > s )
{
	if( pos == n )
	{
		++cnt;
		cout << ans << "\n";
		return;
	}
	multiset< char > copy = s;
	for( char c : s )
	{
		ans[ pos ] = c;
		copy.erase( copy.find( c ) );
		backtrack( pos + 1, copy );
		copy.insert( c );
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> str;
	n = str.length();
	ans.resize( n );
	cout << "The permutations are: " << "\n";
	backtrack( 0, { str.begin(), str.end() } );
	cout << "Count is: " << cnt << "\n";
	return 0;
}
