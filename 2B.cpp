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

int n, a, b, val, t, f;
bool zero = false;
vector< char > ans;
long long arr[ 1005 ][ 1005 ], two[ 1005 ][ 1005 ], five[ 1005 ][ 1005 ], dp2[ 1005 ][ 1005 ], dp5[ 1005 ][ 1005 ];

long long solve2( int i, int j )
{
	if( i < 1 || j < 1 )
	{
		return 1e17;
	}
	if( i == 1 && j == 1 )
	{
		dp2[ i ][ j ] = two[ i ][ j ];
	}
	if( dp2[ i ][ j ] != -1 )
	{
		return dp2[ i ][ j ];
	}
	dp2[ i ][ j ] = two[ i ][ j ] + min( solve2( i, j - 1 ), solve2( i - 1, j ) );
	return dp2[ i ][ j ];
}

long long solve5( int i, int j )
{
	if( i < 1 || j < 1 )
	{
		return 1e17;
	}
	if( i == 1 && j == 1 )
	{
		dp5[ i ][ j ] = five[ i ][ j ];
	}
	if( dp5[ i ][ j ] != -1 )
	{
		return dp5[ i ][ j ];
	}
	dp5[ i ][ j ] = five[ i ][ j ] + min( solve5( i, j - 1 ), solve5( i - 1, j ) );
	return dp5[ i ][ j ];
}

void print2( int i, int j )
{
	if( i == 1 && j == 1 )
	{
		cout << string( ans.rbegin(), ans.rend() ) << "\n";
		exit( EXIT_SUCCESS );
	}
	if( dp2[ i ][ j ] == two[ i ][ j ] + solve2( i, j - 1 ) )
	{
		ans.emplace_back( 'R' );
		print2( i, j - 1 );
	}
	else
	{
		ans.emplace_back( 'D' );
		print2( i - 1, j );
	}
}

void print5( int i, int j )
{
	if( i == 1 && j == 1 )
	{
		cout << string( ans.rbegin(), ans.rend() ) << "\n";
		exit( EXIT_SUCCESS );
	}
	if( dp5[ i ][ j ] == five[ i ][ j ] + solve5( i, j - 1 ) )
	{
		ans.emplace_back( 'R' );
		print5( i, j - 1 );
	}
	else
	{
		ans.emplace_back( 'D' );
		print5( i - 1, j );
	}
}

void print0( int a, int b, int c, int d )
{
	while( a < c )
	{
		ans.emplace_back( 'D' );
		++a;
	}
	while( b < d )
	{
		ans.emplace_back( 'R' );
		++b;
	}
}

void printzero( void )
{
	cout << 1 << "\n";
	print0( 1, 1, a, b);
	print0( a, b, n, n );
	cout << string( ans.begin(), ans.end() ) << "\n";
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	memset( dp2, -1, sizeof( dp2 ) );
	memset( dp5, -1, sizeof( dp5 ) );
	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		for( int j = 1; j <= n; ++j )
		{
			cin >> arr[ i ][ j ];
			val = arr[ i ][ j ];
			t = 0; f = 0;
			if( val != 0 )
			{
				while( val % 2 == 0 )
				{
					++t;
					val /= 2;
				}
				while( val % 5 == 0 )
				{
					++f;
					val /= 5;
				}
				two[ i ][ j ] = t;
				five[ i ][ j ] = f;
			}
			else
			{
				zero = true;
				a = i;
				b = j;
				two[ i ][ j ] = 1e10;
				five[ i ][ j ] = 1e10;
			}
		}		
	}
	solve2( n, n );
	solve5( n, n );
	if( dp2[ n ][ n ] < dp5[ n ][ n ] )
	{
		if( zero && dp2[ n ][ n ] > 1 )
		{
			printzero();
		}
		else
		{
			cout << dp2[ n ][ n ] << "\n";
			print2( n, n );
		}
	}
	else
	{
		if( zero && dp5[ n ][ n ] > 1 )
		{
			printzero();
		}
		else
		{
			cout << dp5[ n ][ n ] << "\n";
			print5( n, n );
		}
	}
	return 0;
}
