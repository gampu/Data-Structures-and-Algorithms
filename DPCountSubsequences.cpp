// https://codeforces.com/contest/1183/problem/H

n, k = map( int, raw_input().split() )
s = raw_input()

last = [ 0 for i in range( 0, 150 ) ]
sum = [ 0 for i in range( 0, 105 ) ]
dp = [ [ 0 for j in range( 0, 105 ) ] for i in range( 0, 105 ) ]
sum[ 0 ] = 1
dp[ 0 ][ 0 ] = 1

for i in range( 1, n + 1 ):
	for j in range( i, 0, -1 ):
		dp[ i ][ j ] = dp[ i ][ j ] + sum[ j - 1 ]
		sum[ j ] = sum[ j ] + dp[ i ][ j ]
	if last[ ord( s[ i - 1 ] ) ]:
		pos = last[ ord( s[ i - 1 ] ) ]
		for j in range( pos, 0, -1 ):
			sum[ j ] = sum[ j ] - dp[ pos ][ j ]
			dp[ pos ][ j ] = 0
	last[ ord( s[ i - 1 ] ) ] = i

ans = 0
for i in range( n, -1, -1 ):
	seq = min( k, sum[ i ] )
	k = k - seq
	ans = ans + seq * ( n - i )
if k:
	ans = -1
print ans
