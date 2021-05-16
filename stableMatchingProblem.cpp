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

// Stable Matching Problem 
// https://www.spoj.com/problems/STABLEMP/

int t, n, value, info, u, w;
vector< int > high( 510 ), umatching( 510 ), wmatching( 510 );
vector< vector< int > > brank( 510, vector< int >( 510 ) ), grank( 510, vector< int >( 510 ) );
queue< int > q;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 1; z <= t; ++z )
	{
		fill( high.begin(), high.end(), 1 );
		fill( umatching.begin(), umatching.end(), -1 );
		fill( wmatching.begin(), wmatching.end(), -1 );
		cin >> n;
		for( int i = 1; i <= n; ++i )
		{
			cin >> info;
			value = n;
			for( int j = 1; j <= n; ++j )
			{
				cin >> info;
				grank[ i ][ info ] = value;
				--value;
			}
		}
		for( int i = 1; i <= n; ++i )
		{
			cin >> info;
			for( int j = 1; j <= n; ++j )
			{
				cin >> info;
				brank[ i ][ j ] = info;
			}		
		}
		for( int i = 1; i <= n; ++i )
		{
			q.push( i );		
		}
		while( !q.empty() )
		{
			u = q.front();	q.pop();
			w = brank[ u ][ high[ u ] ];	++high[ u ];
			if( wmatching[ w ] == -1 )
			{
				umatching[ u ] = w;
				wmatching[ w ] = u;
			}
			else
			{
				if( grank[ w ][ u ] > grank[ w ][ wmatching[ w ] ] )
				{
					umatching[ wmatching[ w ] ] = -1;
					q.push( wmatching[ w ] );
					umatching[ u ] = w;
					wmatching[ w ] = u;
				}
				else
				{
					q.push( u );
				}
			}
		}
		for( int i = 1; i <= n; ++i )
		{
			cout << i << " " << umatching[ i ] << "\n";		
		}
	}	
	return 0;
}
