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

// Convex Hull Trick.
// Given some x, find the minimum value of y that can be achieved by a line from amongst the set of lines and output the minimum
// value.
// See Notes for explanation with example.

int n, q, t1, t2;
double l = -1e18, r, x;
stack< int > st;
vector< int > ans, lines;
vector< pair< double, double > > ranges;
vector< pair< double, double > > arr( 1e5 + 5 );

double solve( double x )
{
	int l = 0, r = n - 1, mid;
	while( l <= r )
	{
		mid = ( l + r ) >> 1;
		if( x < ranges[ mid ].first )
		{
			r = mid - 1;
		}
		else if( x > ranges[ mid ].second )
		{
			l = mid + 1;
		}
		else
		{
			return arr[ lines[ mid ] ].first * x + arr[ lines[ mid ] ].second;
		}
	}
}

double intersection( double m1, double c1, double m2, double c2 )
{
	return ( c2 - c1 ) / ( m1 - m2 );
}

bool solve( int i, int t1, int t2 )
{
	if( intersection( arr[ i ].first, arr[ i ].second, arr[ t2 ].first, arr[ t2 ].second ) < 
		intersection( arr[ t1 ].first, arr[ t1 ].second, arr[ t2 ].first, arr[ t2 ].second ) )
	{
		return true;
	}
	return false;
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> q;
	for( int i = 1; i <= n; ++i )
	{
		cin >> arr[ i ].first >> arr[ i ].second;		
	}
	sort( arr.begin() + 1, arr.begin() + n + 1, greater< pair< double, double > >() );
	st.push( 1 );
	if( n >= 2 )
	{
		st.push( 2 );
		for( int i = 3; i <= n; ++i )
		{
			while( st.size() >= 2 && con )
			{
				t1 = st.top(); st.pop();
				t2 = st.top(); st.push( t1 );
				if( !solve( i, t1, t2 ) )
				{
					break;
				}
				st.pop();
			}
			st.push( i );
		}
	}
	while( !st.empty() )
	{
		ans.emplace_back( st.top() );
		st.pop();
	}
	reverse( ans.begin(), ans.end() );
	n = int( ans.size() );
	for( int i = 1; i <= n - 1; ++i )
	{
		r = intersection( arr[ ans[ i ] ].first, arr[ ans[ i ] ].second, arr[ ans[ i - 1 ] ].first, arr[ ans[ i - 1 ] ].second );
		ranges.emplace_back( l, r );
		lines.emplace_back( ans[ i - 1 ] );
		l = r;
	}
	r = 1e18;
	ranges.emplace_back( l, r );
	lines.emplace_back( ans[ n - 1 ] ); 
	n = ranges.size();
	for( int i = 1; i <= q; ++i )
	{
		cin >> x;
		cout << solve( x ) << "\n";
	}
	return 0;
}
/*
4 2 
0.666666 1.333333
0 4
-0.5 3
-3 12
3 
5
1.5
-3
*/
