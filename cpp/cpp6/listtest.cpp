
#include "listtest.h"

#include <random>
#include <chrono>
#include <algorithm>
#include <vector>

void sort_assign( std::list< std::string > & v )
{
    for (auto i = v. begin( ); i != v. end( ); ++ i)
    {
	for (auto j = v. begin( ); j != v. end( ); ++ j)
    	    {
		std::string s = *j;
		*j = *i;
		*i = s;
    	    }
    }
}

void listtest::sort_move( std::list< std::string > & v )
{
    for ( auto q = v. begin( ); q != v. end( ); ++ q)
    {
	for ( auto p = v. begin( ); p != v. end( ); ++ p)
	{
	    if (  *p > *q)
	    {
		std::swap(*p, *q);
	    }
	}
    }
}

std::ostream&
operator << ( std::ostream& out, const std::list< std::string > & list0)
{
    out << "{ ";

    std::list< std::string >::const_iterator i;

    for( i = list0.begin(); i != list0.end(); ++i)
    {
	out << *i << ", ";
    }	

    out << "}";

    return out;
}
