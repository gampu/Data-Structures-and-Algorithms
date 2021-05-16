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
	bool isEnd = false;
	map< char, struct trieNode > m;
};
typedef struct trieNode TrieNode;

int n, q;
string s;
TrieNode Root;
TrieNode* current;

void insert( void )
{
	current = &Root;
	for( int j = 0; j <= s.length() - 1; ++j )
	{
		if( current->m.find( s[ j ] ) == current->m.end() )
		{
			TrieNode node;
			current->m[ s[ j ] ] = node;
		}
		current = &( current->m[ s[ j ] ] );
	}
	current->isEnd = true;
}

bool search( void )
{
	current = &Root;
	for( int j = 0; j <= s.length() - 1; ++j )
	{
		if( current->m.find( s[ j ] ) == current->m.end() )
		{
			return false;
		}
		current = &( current->m[ s[ j ] ] );
	}
	return current->isEnd;
}

bool prefixSearch( void )
{
	current = &Root;
	for( int j = 0; j <= s.length() - 1; ++j )
	{
		if( current->m.find( s[ j ] ) == current->m.end() )
		{
			return false;
		}
		current = &( current->m[ s[ j ] ] );
	}
	return true;
}

int main( void )
{
	cin >> n;
	for( int i = 0; i <= n - 1; ++i )
	{
		cin >> s;
		insert();		
	}
	cin >> q;
	for( int i = 0; i <= q - 1; ++i )
	{
		cin >> s;
		cout << ( search() ? "YES" : "NO" ) << "\n";
	}
	cin >> q;
	for( int i = 0; i <= q - 1; ++i )
	{
		cin >> s;
		cout << ( prefixSearch() ? "YES" : "NO" ) << "\n";
	}
	return 0;
}
