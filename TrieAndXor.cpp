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

struct trieNode
{
	int cnt = 0;
	struct trieNode* m[ 2 ] = { 0, 0 }; 
};
typedef struct trieNode TrieNode;

// https://codeforces.com/contest/706/problem/D
// Application of Trie to insert, delete a number from a multiset and query for maximum xor with n.
// Max number that can be inserted is of 30 bits. 

int q, n, pos, p;
char type;
TrieNode Root;
TrieNode* cur;
vector< bool > arr( 30, 0 );

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

int query( int n )
{
	binary( n );
	int ans = 0, p = ( 1 << 29 );
	cur = &Root;
	for( int i = 0; i <= 29; ++i )
	{
		if( cur->m[ ( arr[ i ] ^ 1 ) ] != 0 )
		{
			ans += ( arr[ i ] ^ 1 ) * p;
			cur = cur->m[ ( arr[ i ] ^ 1 ) ];
		}
		else
		{
			ans += arr[ i ] * p;
			cur = cur->m[ arr[ i ] ];
		}
		p >>= 1;
	}
	return ( n ^ ans );
}

int main( void )
{	
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	insert( 0 );
	cin >> q;
	for( int i = 1; i <= q; ++i )
	{
		cin >> type >> n;
		if( type == '+' )
		{
			insert( n );
		}
		else if( type == '-' )
		{	
			binary( n );
			erase( &Root, ( &Root )->m[ arr[ 0 ] ], 0 );
		}
		else
		{
			cout << query( n ) << "\n";
		}
	}
	return 0;
}
