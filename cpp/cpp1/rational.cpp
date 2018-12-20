#include "rational.h"

int rational::gcd(int n1, int n2) 
{
	if(n1 == 0) return n2;
	else if (n2 == 0) return n1;
	else {
		if(n2 < 0) n2 = -n2;
		if(n1 < 0) n1 = -n1;
		int r = n1 % n2;

		while(r != 0) {
			n1 = n2;
			n2 = r;
			r = n1 % n2;	
		}		
		return n2;
	}
}

void rational::normalize() 
{
 
	if(denum < 0) 
	{
	   num = -num;
	   denum = -denum;
	};
	int g = gcd(num, denum);

	if ( g == 0 ) std::cout << "error!";

	num = num / g;
	denum = denum / g;
}

std::ostream& operator << (std::ostream& out, const rational& r) 
{
	if( r.denum == 1 ) out << r.num;

	else if ( r.denum == 0 ) out << "invalid fraction!";

	else out << r.num << "/" << r.denum;
}

rational operator - ( rational r ) 
{
	return { -r. num, r. denum };
}


rational operator + ( const rational& r1, const rational& r2 ) 
{
	int num = (r1.num * r2.denum + r2.num * r1.denum) ;
        int denum = (r1.denum * r2.denum);
	return rational (num, denum);
}

rational operator - ( const rational& r1, const rational& r2 ) 
{
	int num = (r1.num * r2.denum - r2.num * r1.denum);
	int denum = (r1.denum * r2.denum);
	return rational (num, denum);
}

rational operator * ( const rational& r1, const rational& r2 ) 
{
	int num = (r1.num * r2.num);
 	int denum = (r1.denum * r2.denum);	
	return rational (num, denum);
}

rational operator / ( const rational& r1, const rational& r2 ) 
{
	int num = (r1.num * r2.denum);
	int denum = (r1.denum * r2.num);	
	return rational (num, denum);
}

bool operator == ( const rational& r1, const rational& r2 ) 
{
	if(r1.num == r2.num & r1.denum == r2.denum) return true;
	else return false;
}

bool operator != ( const rational& r1, const rational& r2 ) 
{
	if(r1.num != r2.num || r1.denum != r2.denum) return true;
	else return false;
}



