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
vector< vector< int > > adj( N ), adjscc( N );
vector< int > num( N, 0 ), pred( N, 0 ), onStack( N, 0 ), scc( N, -1 );
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
		w = s.top(); s.pop();
		onStack[ w ] = 0;
		scc[ w ] = cnt;
		while( w != v )
		{
			cout << w + 1 << " ";
			w = s.top(); s.pop();
			onStack[ w ] = 0;
			scc[ w ] = cnt;
		}
		cout << w + 1 << "\n";
		++cnt;
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
	cout << "Edges of the SCC compressed graph are: " << "\n";
	for( int v = 0; v <= n - 1; ++v )
	{
		for( int u : adj[ v ] )
		{
			a = scc[ v ];
			b = scc[ u ];
			if( a != b )
			{
				adjscc[ a ].emplace_back( b );
				cout << a + 1 << " " << b + 1 << "\n";
			}
		}
	}
	cout << "Total SCCs: " << cnt << "\n"; // total count of SCCs
	return 0;
}


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
 
int k = 1, n, m, a, b, w, cnt = 1, N = 1e5 + 5;
long long ans = 0;
vector< vector< int > > adj( N );
vector< set< int > > adjscc( N );
vector< int > num( N, 0 ), pred( N, 0 ), onStack( N, 0 ), scc( N, -1 ), coins( N, 0 );
vector< long long > sum( N, 0 ), dp( N, 0 );
stack< int > s;
 
void strongDFS( int v )
{
	num[ v ] = pred[ v ] = k;
	++k;
	s.push( v );
	onStack[ v ] = 1;
	for( int u : adj[ v ] )
	{
		if( !num[ u ] )
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
		w = s.top(); s.pop();
		onStack[ w ] = 0;
		scc[ w ] = cnt;
		sum[ cnt ] += coins[ w ];
		while( w != v )
		{
			w = s.top(); s.pop();
			onStack[ w ] = 0;
			scc[ w ] = cnt;
			sum[ cnt ] += coins[ w ];
		}
		++cnt;
	}
}
 
long long solve( int v )
{
	if( dp[ v ] != 0 )
	{
		return dp[ v ];
	}
	for( int u : adjscc[ v ] )
	{
		solve( u );
		dp[ v ] = max( dp[ v ], dp[ u ] );
	}
	dp[ v ] += sum[ v ];
	return dp[ v ];
}
 
int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> m;
	for( int i = 1; i <= n; ++i )
	{
		cin >> coins[ i ];		
	}
	for( int i = 1; i <= m; ++i )
	{
		cin >> a >> b;
		adj[ a ].emplace_back( b );
	}
	for( int v = 1; v <= n; ++v )
	{
		if( !num[ v ] )
		{
			strongDFS( v );
		}
	}
	for( int v = 1; v <= n; ++v )
	{
		a = scc[ v ];
		for( int u : adj[ v ] )
		{
			b = scc[ u ];
			if( a != b )
			{
				adjscc[ a ].insert( b );
			}
		}
	}
	for( int i = 1; i <= cnt - 1; ++i )
	{
		ans = max( ans, solve( i ) );
	}
	cout << ans << "\n";
	return 0;
}
