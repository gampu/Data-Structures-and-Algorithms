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

struct point
{
	int x;
	int y;
	bool operator<( const struct point& b ) const
	{
		return ( x < b.x || x == b.x && y < b.y );
	}
};
typedef struct point pt;

int n, a, b;
vector< pt > arr, ans;
pt p;

int dist( pt& a )
{
	return ( a.x - p.x ) * ( a.x - p.x ) + ( a.y - p.y ) * ( a.y - p.y );
}

bool comp( pt& b, pt& c )
{
	int w, x, y, z;
	w = b.y - p.y;
	x = b.x - p.x;
	y = c.y - p.y;
	z = c.x - p.x;
	if( w * z < y * x )
	{
		return true;
	}
	else if( w * z == y * x )
	{
		return dist( b ) < dist( c );
	}
	return false;
}

int cross( pt a, pt b )
{
	return ( a.x * b.y - a.y * b.x );
}

bool cw( pt a, pt b, pt c )
{
	return cross( { b.x - c.x, b.y - c.y }, { a.x - b.x, a.y - b.y } ) > 0;
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 0; i <= n - 1; ++i )
	{	
		cin >> a >> b;
		arr.push_back( { a, b } );	
	}
	auto it = min_element( arr.begin(), arr.end() );
	swap( arr[ 0 ], arr[ it - arr.begin() ] );
	p = arr[ 0 ];
	sort( arr.begin() + 1, arr.end(), comp );
	ans = { arr[ 0 ], arr[ 1 ] };
	for( int i = 2; i <= n - 1; ++i )
	{
		while( ans.size() >= 2 && !cw( arr[ i ], ans[ ans.size() - 1 ], ans[ ans.size() - 2 ] ) )
		{
			ans.pop_back();
		}
		ans.push_back( arr[ i ] );
	}
	if( ans.size() <= 2 )
	{
		cout << -1 << "\n";
		return 0;
	}
	cout << "\n";
	for( auto c : ans )
	{
		cout << c.x << " " << c.y << "\n";
	}
	return 0;
}
/*
6
0 0
0 3
3 3 
1 2
2 2 
4 4 

0 0
4 4
0 3


8
0 3
1 1
2 2 
4 4 
0 0
1 2
3 1
3 3

0 0
3 1
4 4
0 3


*/
