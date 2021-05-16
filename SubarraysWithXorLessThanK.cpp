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

// Total number of subarrays having xor less than t.
// https://www.spoj.com/problems/SUBXOR/

struct trieNode
{
	int cnt = 0;
	struct trieNode* m[ 2 ] = { 0, 0 }; 
};
typedef struct trieNode TrieNode;

int tests, n, k, val, pos, p;
long long ans = 0;
TrieNode Root;
TrieNode* cur;
vector< int > dp( 1e5 + 5, 0 );
vector< bool > arr( 30, 0 ), t( 30 );

void binary( int n )
{
	pos = 29;
	while( pos >= 0 )
	{
		arr[ pos ] = ( n & 1 );
		--pos;
		n >>= 1;
	}
}

void insert( int n )
{
	binary( n );
	cur = &Root;
	for( int i = 0; i <= 29; ++i )
	{
		if( cur->m[ arr[ i ] ] == 0 )
		{
			cur->m[ arr[ i ] ] = new TrieNode();
		}
		cur = cur->m[ arr[ i ] ];
		++cur->cnt;
	}
}

void erase( TrieNode* par, TrieNode* cur, int pos )
{
	if( pos != 29 )
	{
		erase( cur, cur->m[ arr[ pos + 1 ] ], pos + 1 );
	}
	--cur->cnt;
	if( cur->cnt == 0 )
	{
		par->m[ arr[ pos ] ] = 0;
		delete( cur );
	}
}

void erase( int n )
{
	binary( n );
	erase( &Root, ( &Root )->m[ arr[ 0 ] ], 0 );
}

int query( int n )
{
	binary( n );
	int ans = 0;
	cur = &Root;
	for( int i = 0; i <= 29 && cur != 0; ++i )
	{
		if( t[ i ] && cur->m[ arr[ i ] ] != 0 )
		{
			ans += ( cur->m[ arr[ i ] ] )->cnt;
		}
		cur = cur->m[ ( arr[ i ] ^ t[ i ] ) ];
	}
	return ans;
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> tests;
	for( int z = 1; z <= tests; ++z )
	{
		ans = 0;
		cin >> n >> k;
		binary( k );
		t = arr;
		for( int i = 1; i <= n; ++i )
		{
			cin >> val;
			dp[ i ] = dp[ i - 1 ] ^ val;
			insert( dp[ i ] );		
		}
		for( int i = 1; i <= n; ++i )
		{
			ans += query( dp[ i - 1 ] );
			erase( dp[ i ] );		
		}
		cout << ans << "\n";
	}
	return 0;
}
