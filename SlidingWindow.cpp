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

// Given an array arr and an integer k. Find the maximum for each and every contiguous subarray of size k.
// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0/?ref=self

int t, n, k, p;
vector< int > arr;
deque< int > q;

void add( int c )
{
	while( !q.empty() && q.back() < c )
	{
		q.pop_back();
	}
	q.push_back( c );
}

void remove( int c )
{
	if( !q.empty() && q.front() == c )
	{
		q.pop_front();
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 1; z <= t; ++z )
	{
		arr.clear();
		q.clear();
		p = 0;
		cin >> n >> k;
		arr.resize( n );
		for( int i = 0; i <= n - 1; ++i )
		{
			cin >> arr[ i ];		
		}
		for( int i = 0; i <= k - 1; ++i )
		{
			add( arr[ i ] );
		}
		cout << q.front() << " ";
		for( int i = k; i <= n - 1; ++i )
		{
			remove( arr[ p ] );
			++p;
			add( arr[ i ] );
			cout << q.front() << " ";
		}
		cout << "\n";	
	}
	return 0;
}
