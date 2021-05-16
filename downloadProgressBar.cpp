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

#include<unistd.h>
using namespace std;

// A simple progress bar simulator
// This code can be used to make something larger by incorporating threads

int main( void )
{
    for( int i = 1; i <= 10; ++i )
    {
		sleep( 1 );
        for( int j = 1; j <= i - 1 + 5; ++j )
        {
            printf( "\b" );
        }
        printf( "%c%d%c%c", '[', i * 10, '%', ']' );
        for( int j = 1; j <= i; ++j )
        {
            printf( "%c", '.' );
        }
        fflush( stdout );
    }
    puts( "" );                
    return 0;
}
