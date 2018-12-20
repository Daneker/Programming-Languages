
#include "rational.h"
#include "matrix.h"

int main( int argc, char* argv [ ] )
{

  rational r1 = rational(1+2);
  rational r2 = 1+2;
  r2 = rational(3);
  std::cout << r2 << std::endl;
   /*rational r1( 2, -6 );
	std::cout << r1 << "\n";
   rational r2( 4, 3 ); 
	std::cout << r2 << "\n";
   rational r3( -5, 6 );
	std::cout << r3 << "\n";
   rational r4( 1, 2 );
	std::cout << -r4 << "\n";

	std::cout << "the sum of " << r1 << " and " << r2 << "is " << (r1 + r2) << "\n";

   std::cout << rational::gcd ( -5, 60 ) << "\n";

   matrix m1 = { {{1,2}, {-2,7}}, {{1,3}, {2,8}} };
   std::cout << m1 << "\n";

   matrix m2 = { {{-1,3}, {2,5}}, {{2,7}, {-1,7}} };
   std::cout << m2 << "\n";

   std::cout << m1 * m2 << "\n";
   
   matrix m3 = {{4, 5}, {-1, 2}};
   std::cout << m1.determinant() << "\n" << "\n";

   std::cout << m1.inverse() << "\n";
   std::cout << m1.adjugate() << "\n";
   std::cout << m1.inverse() * m1 << "\n";

   matrix temp1 = ( m1 * m2 ) * m3;
   matrix temp2 = m1 * ( m2 * m3 );

   if (temp1 == temp2) 
   {
	std::cout << "they are equal" << "\n";
   } else 
   {
	std::cout << "you broke the math!" << "\n";
   }

   temp1 = ( m1 + m2 ) * m3;
   temp2 = (m1 * m3) + (m2 * m3);

   if (temp1 == temp2) 
   {
	std::cout << "they are equal!" << "\n";
   } else 
   {
	std::cout << "you broke the math!" << "\n";
   }

   int v = 5;   
   temp1 = m1 * ( m2 * v );
   temp2 = ( m1 * m2 ) * v;
   
   if (temp1 == temp2) 
   {
	std::cout << "they are equal!" << "\n";
   } else 
   {
	std::cout << "you broke the math!" << "\n";
   }

   temp1 = m1 * m2;
   
   if ((m1.determinant() * m2.determinant()) == temp1.determinant()) 
   {
	std::cout << "they are equal!" << "\n";
   } else 
   {
	std::cout << "you broke the math!" << "\n";
   }

   temp1 = m1 * m1.inverse();
   temp2 = m1.inverse() * m1;

   if (temp1  == matrix::identity()) 
   {
	std::cout << "they are equal!" << "\n";
   } else 
   {
	std::cout << "you broke the math!" << "\n";
   }

   if (temp2 == matrix::identity()) 
   {
	std::cout << "they are equal!" << "\n";
   } else 
   {
	std::cout << "you broke the math!" << "\n";
   }
*/




}

