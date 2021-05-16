// https://practice.geeksforgeeks.org/problems/find-x-and-y-in-linear-equation/0/?ref=self
// Given ax + by = c, find point ( x, y ) such that x >= 0 && y >= 0;
// To prove: Whether ( x, y ) is unique.

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
#include<cstring>
using namespace std;

int t;
long long a, b, c, X1, Y1, X2, Y2;

void gcd( long long a, long long b, long long & d, long long & x, long long& y )
{
	if( b == 0 )
	{
		d = a;
		x = 1;
		y = 0;
	}
	else
	{
		long long x1, y1;
		gcd( b, a % b, d, x1, y1 );
		x = y1;
		y = x1 - ( a / b ) * y1;
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> t;
	for( int z = 1; z <= t; ++z )
	{
		cin >> a >> b >> c;
		long long d, x, y;	
		gcd( abs( a ), abs( b ), d, x, y );
		if( c % d != 0 )
		{
			cout << "No solution" << "\n";
			continue;
		}
		x *= c / d;
		y *= c / d;
		X1 = x;
		Y1 = y;
		while( X1 < 0 )
		{
			X1 += b / d;
			Y1 -= a / d;
		}
		if( Y1 >= 0 )
		{
			cout << X1 << " " << Y1 << "\n";
			continue;
		}
		X2 = x;
		Y2 = y;
		while( Y2 < 0 )
		{
			X2 -= b / d;
			Y2 += a / d;
		}
		if( X2 >= 0 )
		{
			cout << X2 << " " << Y2 << "\n";
			continue;
		}
		cout << "No solution" << "\n";
	}
	return 0;
}

// https://codeforces.com/contest/7/problem/C
// Given ax + by + c = 0, find any point on this line.

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
#include<cstring>
using namespace std;

long long int a, b, c;
void gcd( long long int a, long long int b, long long int& d, long long int& x, long long int& y )
{
	if( b == 0 )
	{
		d = a;
		x = 1;
		y = 0;
	}
	else
	{
		long long int x1, y1;
		gcd( b, a % b, d, x1, y1 );
		x = y1;
		y = x1 - ( a / b ) * y1;
	}
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> a >> b >> c;
	if( c > 0 )
	{
		a *= -1;
		b *= -1;
	}
	else
	{
		c *= -1;
	}
	long long int d, x, y;	
	gcd( abs( a ), abs( b ), d, x, y );
	if( c % d != 0 )
	{
		cout << -1 << endl;
		return 0;
	}
	x *= c / d;
	y *= c / d;
	if( a < 0 )
	{
		x *= -1;
	}
	if( b < 0 )
	{
		y *= -1;
	}
	cout << x << " " << y << endl;
	return 0;
}
