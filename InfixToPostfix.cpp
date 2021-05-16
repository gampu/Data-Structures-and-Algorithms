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

// https://www.spoj.com/problems/ONP/
// Convert an Infix expression to Postfix expression

int t;
string s;
map< char, int > priority = { { '+', 1 }, { '-', 2 }, { '*', 3 }, { '/', 4 }, { '^', 5 } };
vector< char > ans;
stack< char > st;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 1; z <= t; ++z )
	{
		ans.clear();
		st = stack< char >();
		cin >> s;
		s = '(' + s + ')';
		for( int i = 0; i <= s.length() - 1; ++i )
		{
			if( s[ i ] >= 'a' && s[ i ] <= 'z' )
			{
				ans.emplace_back( s[ i ] );
			}
			else if( s[ i ] == '(' )
			{
				st.push( s[ i ] );
			}
			else if( s[ i ] == ')' )
			{
				while( st.top() != '(' )
				{
					ans.emplace_back( st.top() );
					st.pop();
				}
				st.pop();
			}
			else
			{
				while( priority[ st.top() ] > priority[ s[ i ] ] )
				{
					ans.emplace_back( st.top() );
					st.pop();
				}
				st.push( s[ i ] );
			}
		}
		cout << string( ans.begin(), ans.end() ) << "\n";
	}
	return 0;
}
