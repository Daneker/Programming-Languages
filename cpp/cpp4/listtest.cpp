
#include "listtest.h"
#include <string>
#include <random>
#include <chrono>
#include <algorithm>

void listtest::sort_move( std::list< std::string > & v )
{
   for( auto j = v. begin( ); j != v. end( ); ++ j )
   {
      for( auto i = v. begin( ); i != j; ++ i )
      {
          if( *i > *j )
              std::swap( *i, *j );
      }
   }
}

void listtest::sort_assign( std::list< std::string > & v )
{
   for( auto j = v. begin( ); j != v. end( ); ++ j )
      for( auto i = v. begin( ); i != j; ++ i )
      {
          if( *i > *j )
          {
             std::string s = *i;
             *i = *j;
	     *j = s;
	  }
      }
}

std::ostream& 
operator << ( std::ostream& out, const std::list< std::string > & list) {
   // auto p = std::list< std::string >::const_iterator p;

   out << "{";
   for( auto p = list. begin( ); p != list. end( ); ++p) 
   {
      if(p != list.begin()) out << ",";
      out << " " << *p;
   }
   out << " }";
   return out;
}

