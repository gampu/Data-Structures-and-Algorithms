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

int t;
long long n, ten = 1;
vector< long long > dp( 11, 0 );

long long solve( long long n )
{
	if( n < 10 )
	{
		return n * ( n + 1 ) / 2;
	}
	int x, d;
	vector< int > arr;
	long long num = n, p, nxt;
	while( num )
	{
		d = num % 10;
		arr.emplace_back( d );
		num /= 10;
	}
	reverse( arr.begin(), arr.end() );
	x = arr.size();
	d = arr[ 0 ];
	p = ( long long )pow( 10, x - 1 );
	nxt = n - d * p;
	return dp[ x - 1 ] * d + ( d * ( d - 1 ) * p ) / 2 + ( nxt + 1 ) * d + solve( nxt );
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	for( int i = 1; i <= 10; ++i )
	{
		dp[ i ] = 9 * dp[ i - 1 ] + 45 * ten;
		dp[ i ] += dp[ i - 1 ];
		ten *= 10;
	}
	cin >> t;
	for( int z = 1; z <= t; ++z )
	{	
		cin >> n;
		cout << solve( n ) << "\n";
	}
}
