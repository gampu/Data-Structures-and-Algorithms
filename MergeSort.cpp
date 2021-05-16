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

int n;
vector< int > arr( 6e6+ 5 );

void mergeSort( int l, int r )
{
	if( l == r )
	{
		return;
	}
	int tm = ( l + r ) >> 1;
	mergeSort( l, tm );
	mergeSort( tm + 1, r );
	vector< int > t( r - l + 1 );
	merge( arr.begin() + l, arr.begin() + tm + 1, arr.begin() + tm + 1, arr.begin() + r + 1, t.begin() );
	copy( t.begin(), t.end(), arr.begin() + l );
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		arr[ i ] = rand() % 10000;
	}
	mergeSort( 1, n );
	if( is_sorted( arr.begin() + 1, arr.begin() + n + 1 ) )
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}
	return 0;
}
