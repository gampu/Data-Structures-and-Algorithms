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

// https://www.spoj.com/problems/CLOPPAIR/
// Closest pair of points

struct pt
{
	int x;
	int y;
	int id;
};
typedef struct pt pt;

bool compx( pt& a, pt& b )
{
	return ( a.x < b.x ) || ( a.x == b.x && a.y < b.y );
}

bool compy( pt& a, pt& b )
{
	return a.y < b.y;
}

long double ans = 1e15 + 0.0;
int n, x, y;
pair< int, int > result;
vector< pt > arr;

void update( pt& a, pt& b )
{
	long double res = sqrtl( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
	if( res < ans )
	{
		ans = res;
		result = { a.id, b.id };
	}
}

void solve( int l, int r )
{
	if( l == r )
	{
		return;
	}
	if( l + 1 == r )
	{
		update( arr[ l ], arr[ r ] );
		sort( arr.begin() + l, arr.begin() + r + 1, compy );
		return;
	}
	int tm = ( r + l ) >> 1;
	int mid = arr[ tm ].x;
	solve( l, tm );
	solve( tm + 1, r );
	vector< pt > t;
	merge( arr.begin() + l, arr.begin() + tm + 1, arr.begin() + tm + 1, arr.begin() + r + 1, back_inserter( t ), compy );
	for( int i = 0; i <= t.size() - 1; ++i )
	{
		if( fabsl( ( long double )t[ i ].x - mid ) < ans )
		{
			for( int j = i - 1; j >= 0 && t[ j ].y > t[ i ].y - ans; --j )
			{
				update( t[ i ], t[ j ] );
			}
		}
	}
	copy( t.begin(), t.end(), arr.begin() + l );
	return;
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		cin >> x >> y;
		arr.push_back( { x, y, i } );
	}
	sort( arr.begin(), arr.end(), compx );
	solve( 0, n - 1 );
	cout << ans << "\n";
	cout << result.first << " " << result.second << "\n";
	return 0;
}
