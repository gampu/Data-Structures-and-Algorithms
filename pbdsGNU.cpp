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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree< int, null_type, less< int >, rb_tree_tag, tree_order_statistics_node_update > pbds;

pbds s;
int q, x;
char c;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> q;
	for( int i = 1; i <= q; ++i )
	{
		cin >> c >> x;
		if( c == 'I' )
		{
			s.insert( x );
		}
		else if( c == 'D' )
		{
			s.erase( x );
		}
		else if( c == 'K' )
		{
			if( s.find_by_order( x - 1 ) == s.end() )
			{
				cout << "invalid" << "\n";
			}
			else
			{
				cout << *( s.find_by_order( x - 1 ) ) << "\n";
			}
		}
		else
		{
			cout << s.order_of_key( x ) << "\n";
		}
	}		
	return 0;
}
// 1. https://www.spoj.com/problems/ORDERSET/
