from turtle import *

N = 500

def solve( len ):
	if len <= 20:
		forward( len )
	else:
		solve( len / 4 )
		left( 60 )
		solve( len / 4 )
		right( 120 )
		solve( len / 4 )
		left( 60 )
		solve( len / 4 )
	
color( 'red', 'blue' )
speed( 0 )
setpos( -250, 150 )
begin_fill()
for i in range( 1, 4 ):
	solve( N )
	right( 120 )
end_fill()
done() 
