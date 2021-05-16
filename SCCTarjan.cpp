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

int i = 1, n, m, a, b, w, cnt = 0, N = 1e5 + 5;
vector< vector< int > > adj( N );
vector< int > num( N, 0 ), pred( N, 0 ), onStack( N, 0 );
stack< int > s;

void strongDFS( int v )
{
	num[ v ] = pred[ v ] = i;
	++i;
	s.push( v );
	onStack[ v ] = 1;
	for( int u : adj[ v ] )
	{
		if( num[ u ] == 0 )
		{
			strongDFS( u );
			pred[ v ] = min( pred[ v ], pred[ u ] );
		}
		else if( onStack[ u ] )
		{
			pred[ v ] = min( pred[ v ], num[ u ] );
		}
	}
	if( pred[ v ] == num[ v ] )
	{	
		++cnt;
		w = s.top(); s.pop();
		onStack[ w ] = 0;
		while( w != v )
		{
			cout << w << " ";
			w = s.top(); s.pop();
			onStack[ w ] = 0;
		}
		cout << w << "\n";
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> m;
	for( int i = 0; i <= m - 1; ++i )
	{
		cin >> a >> b; // 1 based vertex numbering
		--a;
		--b;
		adj[ a ].emplace_back( b );
	}
	for( int v = 0; v <= n - 1; ++v )
	{
		if( num[ v ] == 0 )
		{
			strongDFS( v );
		}
	}
	cout << "Ans: " << cnt << "\n"; // total count of SCCs
	return 0;
}
