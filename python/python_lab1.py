from scipy import *
from scipy.linalg import *

def solution( ) :
	print( "here are the answers of Daneker Nurgaliyeva \n" )

	m1 = array( [ [ 1/2, 1/3 ], [ -2/7, 2/8 ] ] )
	m2 = array( [ [ -1/3, 2/7 ], [ 2/5, -1/7 ] ] )
	m3 = array( [ [ -1/5, 2/3 ], [ 1/8, 3/11 ] ] )
	p = array( [ [ -1/30, 2/21 ], [ 41/210, -23/196 ] ] )
	I = array( [ [ 42, -56 ], [ 48, 84 ] ] ) / 37
	v = array( [ 3.0, -1 ] )

	print(" This is part 1 \n" )
	print(" the product of m1 and m2 is " )
	print( dot(m1, m2) )
	print(" the difference of product of m1 and m2 and p is " )
	print( dot(m1, m2) - p )
	print("so it is verified\n")

	print(" This is part 2 \n" )
	print(" the inverse of m1 is " )
	print( inv( m1) )
	print(" the difference of inverse of m1 and I is " )
	print( inv( m1) - I )
	print("so it is verified\n")

	print(" This is part 3 \n" )
	print(" the product of (m1 and m2) and m3 is " )
	print( dot(dot(m1, m2), m3) )
	print(" the product of m1 and (m2 and m3) is " )
	print( dot(m1, dot(m2, m3) ))
	print(" the difference is " )
	print( dot(dot(m1, m2), m3) - dot(m1, dot(m2, m3) ) )
	print("so it is verified that matrix mult is associative\n")

	print(" This is part 4 \n" )
	print(" multiplication of m1 and m2+m3 is " )
	print( dot(m1, (m2+m3)) )
	print( " or " )
	print( (dot(m1, m2) + dot(m1, m3) ))
	print( "the difference is " )
	print( dot(m1, (m2+m3)) - (dot(m1, m2) + dot(m1, m3) ) )
	print(" multiplication of m1+m2 and m3 is " )
	print( dot((m1+m2), m3) )
	print( " or " )
	print( (dot(m1, m3) + dot(m2, m3) ))
	print( "the difference is " )
	print( dot((m1+m2), m3) - (dot(m1, m3) + dot(m2, m3) ) )
	print("so it is verified that matrix mult is distributive\n")

	print(" This is part 5 \n" )
	print(" the composition m1(m2(v)) is " )
	print( dot(m1, dot(m2, v)) )
	print( " or " )
	print( dot(dot(m1, m2), v) )
	print( "the difference is " )
	print( dot(m1, dot(m2, v)) - dot(dot(m1, m2), v) )
	print("\n")

	print(" This is part 6 \n" )
	print(" the multiplication of det of m1 and det of m2 is " )
	print( dot(det(m1), det(m2)) )
	print( " or " )
	print( det(dot(m1, m2)) )
	print( "the difference is " )
	print( dot(det(m1), det(m2)) - det(dot(m1, m2) ) )
	print("\n")

	print(" This is part 7 \n" )
	print(" the inverse of m1 multiplied by m1 is " )
	print( dot(m1, inv(m1)) )
	print( " or " )
	print( dot(inv(m1), m1) )
	print( "the difference is " )
	print( dot(m1, inv(m1)) - dot(inv(m1), m1) )
	print("\n")

	print(" the inverse of m2 multiplied by m2 is " )
	print( dot(m2, inv(m2)) )
	print( " or " )
	print( dot(inv(m2), m2) )
	print( "the difference is " )
	print( dot(m2, inv(m2)) - dot(inv(m2), m2) )
	print("\n")

	print(" the inverse of m3 multiplied by m3 is " )
	print( dot(m3, inv(m3)) )
	print( " or " )
	print( dot(inv(m3), m3) )
	print( "the difference is " )
	print( dot(m3, inv(m3)) - dot(inv(m3), m3) )
	print("\n")


