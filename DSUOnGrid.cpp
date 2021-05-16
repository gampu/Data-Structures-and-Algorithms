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

// Finds all connected components of a grid with cells containing a '#' and assigns characters to them.

int n, m, a, b;
char alpha = 'A';
vector< int > parent( 1e4 + 4, -1 ), size( 1e4 + 4 + 3, 0 );
vector< vector< int > > sets( 1e4 + 4 );
vector< vector< char > > arr( 103, vector< char >( 103 ) );

void make_set( int v )
{
	parent[ v ] = v;
	size[ v ] = 1;
	sets[ v ].emplace_back( v );
}
 
int find_set( int v )
{
	return parent[ v ];
}
 
bool unite_set( int a, int b )
{
	a = find_set( a );
	b = find_set( b );
	if( a != b )
	{
		if( size[ a ] < size[ b ] )
		{
			swap( a, b );
		}
		while( !sets[ b ].empty() )
		{
			int v = sets[ b ].back();
			sets[ b ].pop_back();
			sets[ a ].emplace_back( v );
			parent[ v ] = a;
		}
		size[ a ] += size[ b ];
		size[ b ] = 0;
		return true;
	}
	return false;
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> m;
	for( int i = 1; i <= n; ++i )
	{
		for( int j = 1; j <= m; ++j )
		{
			cin >> arr[ i ][ j ];
			if( arr[ i ][ j ] == '#' )
			{
				make_set( ( i - 1 ) * m + j );
			}
		}	
	}
	for( int i = 1; i <= n; ++i )
	{
		for( int j = 1; j <= m; ++j )
		{
			if( arr[ i ][ j ] == '#' )
			{
				if( i - 1 >= 1 && arr[ i - 1 ][ j ] == '#' )
				{
					unite_set( ( i - 1 ) * m + j, ( i - 2 ) * m + j );
				}
				if( j - 1 >= 1 && arr[ i ][ j - 1 ] == '#' )
				{
					unite_set( ( i - 1 ) * m + j, ( i - 1 ) * m + j - 1 );
				}
			}	
		}		
	}
	for( int i = 1; i <= 1e4 + 1; ++i )
	{
		if( sets[ i ].size() >= 1 )
		{
			for( int j = 0; j <= int( sets[ i ].size() ) - 1; ++j )
			{
				a = sets[ i ][ j ] / m + 1;
				b = sets[ i ][ j ] % m;
				if( b == 0 )
				{
					--a;
					b = m;
				}
				arr[ a ][ b ] = alpha;
			}
			++alpha;
		}
	}
	for( int i = 1; i <= n; ++i )
	{
		for( int j = 1; j <= m; ++j )
		{
			cout << arr[ i ][ j ];
		}
		cout << "\n";		
	}	
	return 0;
}
