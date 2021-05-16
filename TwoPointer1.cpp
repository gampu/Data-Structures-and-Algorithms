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

// Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at
// least one time
// https://practice.geeksforgeeks.org/problems/smallest-distant-window/0

// Approach 1 gives TLE on Codeforces

int t, n, ans, k, cur, sum;
string s;
vector< int > cnt( 60 );
set< int > ds;

void add( int j )
{
	if( cnt[ s[ j ] - 65 ] == 0 )
	{
		++cur;
	}
	++cnt[ s[ j ] - 65 ];
}

void remove( int i )
{
	--cnt[ s[ i ] - 65 ];
	if( cnt[ s[ i ] - 65 ] == 0 )
	{
		--cur;
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 0; z <= t - 1; ++z )
	{
		k = 0; cur = 0;
		ds.clear();
		fill( cnt.begin(), cnt.end(), 0 );
		cin >> s;
		n = s.length();
		ans = n;
		ds.insert( s.begin(), s.end() );
		sum = ds.size();
		for( int i = 0; i <= n - 1; ++i )
		{
			if( i > k )
			{
				k = i;
			}
			for( int j = k; j <= n - 1; ++j )
			{
				add( j );
				if( cur == sum )
				{
					ans = min( ans, j - i + 1 );
					remove( j );
					k = j;
					break;
				}
			}
			remove( i );
		}
		cout << ans << "\n";
	}
	return 0;
}

// Aproach 2
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

int n, ans, i = 0, cur = 0, sum;
string s;
vector< int > cnt( 60, 0 );
set< int > ds;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> s;
	ans = n;
	ds.insert( s.begin(), s.end() );
	sum = ds.size();
	for( int j = 0; j <= n - 1; ++j )
	{
		if( cnt[ s[ j ] - 65 ] == 0 )
		{
			++cur;
		}
		++cnt[ s[ j ] - 65 ];
		if( cur == sum )
		{
			while( cnt[ s[ i ] - 65 ] > 1 )
			{
				--cnt[ s[ i ] - 65 ];
				++i;
			}
			ans = min( ans, j - i + 1 );
		}	
	}
	cout << ans << "\n";
	return 0;
}
