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

// Order statistic AVL Tree
// https://www.spoj.com/problems/ALLIN1/

template< typename T >
class Node
{
	public:
		T el;
		Node< T >* par;
		Node< T >* left;
		Node< T >* right;
		int sz, height, bf;
		Node( T value )
		{
			el = value;
			par = 0;
			left = 0;
			right = 0;
			sz = 1;
			height = 1;
			bf = 0;
		}
};

template< typename T >
class Tree
{
	public:
		Node< T >* root = 0;
		int cnt = 0;

		int sz( Node< T >* ptr )
		{
			return ( ptr != 0 ? ptr->sz : 0 );
		}

		int hgt( Node< T >* ptr )
		{
			return ( ptr != 0 ? ptr->height : 0 );
		}

		void update( Node< T >* ptr )
		{
			ptr->sz = sz( ptr->left ) + sz( ptr->right ) + 1;
			ptr->height = max( hgt( ptr->left ), hgt( ptr->right ) ) + 1;
			ptr->bf = hgt( ptr->right ) - hgt( ptr->left );
		}

		void LR( Node< T >* gr, Node< T >* par, Node< T >* ch )
		{
			gr->right = par->left;
			if( gr->right )
			{
				gr->right->par = gr;
			}
			par->left = gr;
			par->par = gr->par;
			gr->par = par;
			if( par->par == 0 )
			{
				root = par;
			}
			else
			{
				if( par->par->left == gr )
				{
					par->par->left = par;
				}
				else
				{
					par->par->right = par;
				}
			}
			update( gr );
			update( par );
		}

		void RR( Node< T >* gr, Node< T >* par, Node< T >* ch )
		{
			gr->left = par->right;
			if( gr->left )
			{
				gr->left->par = gr;
			}
			par->right = gr;
			par->par = gr->par;
			gr->par = par;
			if( par->par == 0 )
			{
				root = par;
			}
			else
			{
				if( par->par->left == gr )
				{
					par->par->left = par;
				}
				else
				{
					par->par->right = par;
				}
			}
			update( gr );
			update( par );
		}

		void balance( Node< T >* ptr )
		{
			while( ptr != 0 )
			{
				update( ptr );
				if( ptr->bf == 2 || ptr->bf == -2 )
				{
					if( ptr->bf == 2 )
					{
						if( ptr->right->bf == -1 )
						{
							RR( ptr->right, ptr->right->left, ptr->right->left->left );
						}
						LR( ptr, ptr->right, ptr->right->right );
					}
					else
					{
						if( ptr->left->bf == 1 )
						{
							LR( ptr->left, ptr->left->right, ptr->left->right->right );
						}
						RR( ptr, ptr->left, ptr->left->left );
					}
					ptr = ptr->par;
				}
				ptr = ptr->par;
			}
		}

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
			node->par = pre;
			++cnt;
			balance( pre );
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
		
		void deleteByCopying( Node< T >*& ptr, Node< T >* par )
		{
			Node< T >* del = ptr, *pre = 0, *p = 0;
			if( ptr->right == 0 )
			{
				ptr = ptr->left;
				if( ptr )
				{
					ptr->par = par;
				}
				balance( par );
			}
			else if( ptr->left == 0 )
			{
				ptr = ptr->right;
				if( ptr )
				{
					ptr->par = par;
				}
				balance( par );
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
					if( pre->left )
					{
						pre->left->par = pre;
					}
				}
				else
				{
					pre->right = p->left;
					if( pre->right )
					{
						pre->right->par = pre;
					}
				}
				balance( pre );
				del = p;
			}
			delete del;
			--cnt;
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
				deleteByCopying( root, pre );
			}
			else if( pre->left == p )
			{
				deleteByCopying( pre->left, pre );
			}
			else
			{
				deleteByCopying( pre->right, pre );
			}
		}

		// Given a val, present in the bst, returns its 1-based index in the ascending sequence of all the elements in bst.
		int query( Node< T >* ptr, T val )
		{
			if( ptr->el == val )
			{
				return sz( ptr->left ) + 1;
			}
			else if( ptr->el > val )
			{
				return query( ptr->left, val );
			}
			else
			{
				return sz( ptr->left ) + 1 + query( ptr->right, val );
			}
		}

		int query( T val )
		{
			return query( root, val );
		}

		// Given a valid 1-based index `ind`, returns the element at `ind` in the ascending sequence of all the elements in bst.
		T queryindex( Node< T >* ptr, int ind )
		{
			int res = sz( ptr->left ) + 1;
			if( res == ind )
			{
				return ptr->el;
			}
			else if( res > ind )
			{
				return queryindex( ptr->left, ind );
			}
			else
			{
				return queryindex( ptr->right, ind - res );
			}
		}

		int queryindex( T ind )
		{
			return queryindex( root, ind );
		}
};

Tree< int > bst;
int type, val, ans;

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	while( true )
	{
		cin >> type;
		if( type == -1 )
		{
			return 0;
		}
		cin >> val;
		if( type == 1 )
		{
			bst.insert( val );
		}
		else if( type == 2 )
		{
			bst.findAndDeleteByCopying( val );
		}
		else if( type == 3 )
		{
			ans = -1;
			if( bst.search( val ) )
			{
				ans = bst.query( val );
			}
			cout << ans << "\n";
		}
		else
		{
			ans = -1;
			if( val != 0 && val <= bst.cnt )
			{
				ans = bst.queryindex( val );
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
