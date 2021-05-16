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

template< typename T >
class Node
{
	public:
		T el;
		Node< T >* left;
		Node< T >* right;
		Node( T value )
		{
			el = value;
			left = 0;
			right = 0;
		}
};

template< typename T >
class Tree
{
	private:
		Node< T >* root = 0;
		int cnt = 0;

	public:
		void insert( T el )
		{
			Node< T > *pre = 0, *p = root, *node = new Node< T >( el );
			if( !p )
			{
				root = node;
				++cnt;
				return;
			}
			while( p != 0 )
			{
				pre = p;
				if( el == p->el )
				{
					free( node );
					return;
				}
				else if( el < p->el )
				{
					p = p->left;
				}
				else
				{
					p = p->right;
				}
			}
			if( el < pre->el )
			{
				pre->left = node;
			}
			else
			{
				pre->right = node;
			}
			++cnt;
		}

		bool search( T el )
		{
			Node< T >* p = root;
			while( p != 0 )
			{
				if( el == p->el )
				{
					return true;
				}
				else if( el < p->el )
				{
					p = p->left;
				}
				else
				{
					p = p->right;
				}
			}
			return false;
		}

		void deleteByMerging( Node< T >*& ptr )
		{
			Node< T >* del = ptr, *p = 0;
			if( ptr->right == 0 )
			{
				ptr = ptr->left;
			}
			else if( ptr->left == 0 )
			{
				ptr = ptr->right;
			}
			else
			{
				p = ptr->left;
				while( p->right )
				{
					p = p->right;
				}
				p->right = ptr->right;
				ptr = ptr->left;
			}
			delete del;
			--cnt;
		}

		void deleteByCopying( Node< T >*& ptr )
		{
			Node< T >* del = ptr, *pre = 0, *p = 0;
			if( ptr->right == 0 )
			{
				ptr = ptr->left;
			}
			else if( ptr->left == 0 )
			{
				ptr = ptr->right;
			}
			else
			{
				pre = ptr;
				p = ptr->left;
				while( p->right )
				{
					pre = p;
					p = p->right;
				}
				ptr->el = p->el;
				if( pre->left == p )
				{
					pre->left = p->left;
				}
				else
				{
					pre->right = p->left;
				}
				del = p;
			}
			delete del;
			--cnt;
		}
				
		void findAndDeleteByMerging( T el )
		{
			if( !search( el ) )
			{
				return;
			}
			Node< T >* p = root, *pre = 0;
			while( p != 0 )
			{
				if( p->el == el )
				{
					break;
				}
				pre = p;
				if( el < p->el )
				{
					p = p->left;
				}
				else
				{
					p = p->right;
				}
			}
			if( pre == 0 )
			{
				deleteByMerging( root );
			}
			else if( pre->left == p )
			{
				deleteByMerging( pre->left );
			}
			else
			{
				deleteByMerging( pre->right );
			}
		}

		void findAndDeleteByCopying( T el )
		{
			if( !search( el ) )
			{
				return;
			}
			Node< T >* p = root, *pre = 0;
			while( p != 0 )
			{
				if( p->el == el )
				{
					break;
				}
				pre = p;
				if( el < p->el )
				{
					p = p->left;
				}
				else
				{
					p = p->right;
				}
			}
			if( pre == 0 )
			{
				deleteByCopying( root );
			}
			else if( pre->left == p )
			{
				deleteByCopying( pre->left );
			}
			else
			{
				deleteByCopying( pre->right );
			}
		}

		void visit( Node< T >* p )
		{
			cout << p->el << " ";
		}

		void preOrder( Node< T >* p )
		{
			if( p )
			{
				visit( p );
				preOrder( p->left );
				preOrder( p->right );
			}
		}
 
		void preOrder( void )
		{
			preOrder( root );
		}

		void inOrder( Node< T >* p )
		{
			if( p )
			{
				inOrder( p->left );
				visit( p );
				inOrder( p->right );
			}
		}
 
		void inOrder( void )
		{
			inOrder( root );
		}

		void postOrder( Node< T >* p )
		{
			if( p )
			{
				postOrder( p->left );
				postOrder( p->right );
				visit( p );
			}
		}
 
		void postOrder( void )
		{
			postOrder( root );
		}
};

Tree< int > bst;
int n, type, val;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( int i = 1; i <= n; ++i )
	{
		cin >> type;
		if( type == 1 )
		{
			cin >> val;
			bst.insert( val );
		}
		else if( type == 2 )
		{
			cin >> val;
			cout << bst.search( val ) << "\n";
		}
		else if( type == 3 )
		{
			cin >> val;
			bst.findAndDeleteByMerging( val );
		}
		else if( type == 4 )
		{
			cin >> val;
			bst.findAndDeleteByCopying( val );
		}
		else
		{
			bst.inOrder();
		}
	}
	return 0;
}
