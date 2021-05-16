#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<utility>
#include<functional>
#include<bitset>
#include<cstring>
using namespace std;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	int n;
	cin >> n;
	for( int a = -n; a <= n; ++a )
	{
		for( int b = -n; b <= n; ++b )
		{
			cout << a << " " << b << "\n";
			if( not( a + b == a ^ b + 2 * ( a & b ) ) )
			{	
				cout << "False" << endl;
			}
		}
	}
	cout << "True" << endl;
	return 0;
}

// Count set bits in the binary representation of integers from 1 to n( both inclusive )

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
long long n;
bitset< 60 > b;
vector< long long > dp( 61, 0 );
 
long long solve( int pos )
{
	for( int i = pos; i >= 0; --i )
	{
		if( b[ i ] )
		{
			b[ i ] = 0;
			return ( long long )b.to_ulong() + 1 + dp[ i ] + solve( i - 1 );
		}	 
	}
	return 0;
}
 
int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );

	for( int i = 1; i <= 60; ++i )
	{
		dp[ i ] = 2 * dp[ i - 1 ] + ( 1LL << ( i - 1 ) );
	}
	cin >> t;
	for( int z = 1; z <= t; ++z )
	{	
		cin >> n;
		b = bitset< 60 >( n );
		cout << solve( 59 ) << "\n";
	}
	return 0;
}
