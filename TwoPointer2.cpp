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

// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string/0

int t, i, ans, sum, cur, a, b;
string s, o;
vector< int > cnt( 60 ), other( 60 );

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 1; z <= t; ++z )
	{
		ans = 1e9;
		i = 0;
		cur = 0;
		sum = 0;
		fill( cnt.begin(), cnt.end(), 0 );
		fill( other.begin(), other.end(), 0 );
		cin >> s >> o;
		for( int j = 0; j <= o.length() - 1; ++j )
		{
			if( other[ o[ j ] - 65 ] == 0 )
			{
				++sum;
			}
			++other[ o[ j ] - 65 ];
		}
		for( int j = 0; j <= s.length() - 1; ++j )
		{
			++cnt[ s[ j ] - 65 ];
			if( cnt[ s[ j ] - 65 ] == other[ s[ j ] - 65 ] )
			{
				++cur;
			}
			if( cur == sum )
			{
				while( cnt[ s[ i ] - 65 ] > other[ s[ i ] - 65 ] )
				{
					--cnt[ s[ i ] - 65 ];
					++i;
				}
				if( ans > j - i + 1 )
				{
					ans = j - i + 1;
					a = j;
					b = i;
				}
			}
		}
		if( ans == 1e9 )
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << s.substr( b, a - b + 1 ) << "\n";
		}
	}
	return 0;
}
