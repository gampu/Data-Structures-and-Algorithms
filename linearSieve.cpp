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

const int N = 1e7;
int lp[ N + 1 ] = { 0 };
vector< int > pr;

int main( void )
{
	for( int i = 2; i <= N; ++i )
	{
		if( lp[ i ] == 0 )
		{
			lp[ i ] = i;
			pr.emplace_back( i );
		}
		for( int j = 0; j <= pr.size() - 1 and pr[ j ] <= lp[ i ] and pr[ j ] * i <= N; ++j )
		{
			lp[ pr[ j ] * i ] = pr[ j ];
		}
	}
	cout << pr.size() << endl;		
	return 0;
}
