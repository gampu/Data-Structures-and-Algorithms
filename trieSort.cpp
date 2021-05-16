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
	int cnt = 0;
};
typedef struct trieNode TrieNode;

int n;
string s;
TrieNode Root;
TrieNode* current;
vector< string > ans;
vector< char > res;

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
	++current->cnt;
}

void trieSort( TrieNode* ptr )
{
	if( ptr->isEnd )
	{
		string val( res.begin(), res.end() );
		for( int i = 1; i <= ptr->cnt; ++i )
		{
			ans.emplace_back( val );		
		}
	}
	for( auto val : ptr->m )
	{
		res.emplace_back( val.first );
		trieSort( &( val.second ) );
		res.pop_back();
	}
}

int main( void )
{
	cin >> n;
	for( int i = 0; i <= n - 1; ++i )
	{
		cin >> s;
		insert();		
	}
	trieSort( &Root );
	for( string val : ans )
	{
		cout << val << " ";
	}
	cout << "\n";
	return 0;
}
