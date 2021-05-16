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

// Order statistic AVL Tree Multiset
//https://cses.fi/problemset/task/1077/

template< typename T >
class Node
{
	public:
		T el;
		Node< T >* par;
		Node< T >* left;
		Node< T >* right;
		int sz, height, bf, eq;
		long long sum = 0;
		Node( T value )
		{
			el = value;
			par = 0;
			left = 0;
			right = 0;
			sz = 1;
			eq = 1;
			height = 1;
			bf = 0;
			sum = value;
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

		long long sum( Node< T >* ptr )
		{
			return ( ptr != 0 ? ptr->sum : 0 );
		}
				
		void update( Node< T >* ptr )
		{
			ptr->sz = sz( ptr->left ) + sz( ptr->right ) + ptr->eq;
			ptr->height = max( hgt( ptr->left ), hgt( ptr->right ) ) + 1;
			ptr->bf = hgt( ptr->right ) - hgt( ptr->left );
			ptr->sum = sum( ptr->left ) + sum( ptr->right ) + 1LL * ptr->eq * ptr->el;
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
					++( p->eq );
					++cnt;
					balance( p );
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

		Node< T >* search( T el )
		{
			Node< T >* p = root;
			while( p != 0 )
			{
				if( el == p->el )
				{
					return p;
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
			return 0;
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
				ptr->eq = p->eq;
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
			Node< T >* p = root, *pre = 0, *ptr = 0;
			ptr = search( el );
			if( !ptr )
			{
				return;
			}
			--( ptr->eq );
			if( ptr->eq )
			{
				--cnt;
				balance( ptr );
				return;
			}
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
		int findIndexGivenVal( Node< T >* ptr, T val )
		{
			if( ptr->el == val )
			{
				return sz( ptr->left ) + 1;
			}
			else if( ptr->el > val )
			{
				return findIndexGivenVal( ptr->left, val );
			}
			else
			{
				return sz( ptr->left ) + ptr->eq + findIndexGivenVal( ptr->right, val );
			}
		}

		int findIndexGivenVal( T val )
		{
			return findIndexGivenVal( root, val );
		}

		// Given a valid 1-based index `ind`, returns the element at `ind` in the ascending sequence of all the elements in bst.
		T findValGivenIndex( Node< T >* ptr, int ind )
		{
			int res = sz( ptr->left );
			if( ind >= res + 1 && ind <= res + ptr->eq )
			{
				return ptr->el;
			}
			else if( ind <= res )
			{
				return findValGivenIndex( ptr->left, ind );
			}
			else
			{
				return findValGivenIndex( ptr->right, ind - ( res + ptr->eq ) );
			}
		}

		T findValGivenIndex( T ind )
		{
			return findValGivenIndex( root, ind );
		}

		//Given a val, return the total number of elements less than or equal to val.
		int countLessThanOrEqual( Node< T >* ptr, T x )
		{
			if( !ptr )
			{
				return 0;
			}
			if( ptr->el <= x )
			{
				return sz( ptr->left ) + ptr->eq + countLessThanOrEqual( ptr->right, x );
			}
			else
			{
				return countLessThanOrEqual( ptr->left, x );
			}
		}

		int countLessThanOrEqual( T x )
		{
			return countLessThanOrEqual( root, x );
		}

		//Given a val, return the sum of all elements less than or equal to val.
		long long sumLessThanOrEqual( Node< T >* ptr, T x )
		{
			if( !ptr )
			{
				return 0;
			}
			if( ptr->el <= x )
			{
				return sum( ptr->left ) + 1LL * ptr->eq * ptr->el + sumLessThanOrEqual( ptr->right, x );
			}
			else
			{
				return sumLessThanOrEqual( ptr->left, x );
			}
		}

		long long sumLessThanOrEqual( T x )
		{
			return sumLessThanOrEqual( root, x );
		}
};

Tree< int > bst;
int n, k, j = 1, med, cnt;
vector< int > arr( 2e5 + 5 );

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n >> k;
	for( int i = 1; i <= n; ++i )
	{
		cin >> arr[ i ];		
	}
	for( int i = 1; i <= k - 1; ++i )
	{
		bst.insert( arr[ i ] );
	}
	for( int i = k; i <= n; ++i, ++j )
	{
		bst.insert( arr[ i ] );
		med = bst.findValGivenIndex( ( k + 1 ) / 2 );
		cnt = bst.countLessThanOrEqual( med );
		cout << bst.root->sum - 2 * bst.sumLessThanOrEqual( med ) - ( bst.cnt - 2 * cnt ) * 1LL * med << " \n"[ i == n ];
		bst.findAndDeleteByCopying( arr[ j ] );
	}
	return 0;
}
