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

// n-queen problem using backtracking
// https://practice.geeksforgeeks.org/problems/n-queen-problem/0

int t, n, m;
vector< int > column( 50 ), lft( 50 ), rgt( 50 ), ans( 50 );
set< vector< int > > s;

void solve( int row )
{
	if( row == n + 1 )
	{
		s.insert( vector< int >( ans.begin() + 1, ans.begin() + m + 1 ) );
		return;
	}
	for( int col = 1; col <= m; ++col )
	{
		if( column[ col ] && lft[ row + col ] && rgt[ row - col + m ] )
		{
			column[ col ] = 0;
			lft[ row + col ] = 0;
			rgt[ row - col + m ] = 0;
			ans[ col ] = row; // as per GFG
			solve( row + 1 );
			column[ col ] = 1;
			lft[ row + col ] = 1;
			rgt[ row - col + m ] = 1;
		}
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 1; z <= t; ++z )
	{
		s.clear();
		fill( column.begin(), column.end(), 1 );
		fill( lft.begin(), lft.end(), 1 );
		fill( rgt.begin(), rgt.end(), 1 );
		cin >> n >> m; // General case
		solve( 1 );
		cout << s.size() << "\n";	
	}	
	return 0;
}
