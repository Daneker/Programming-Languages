#include <fstream>
#include <iostream>
#include <random>
#include "map.h"

int main( int argc, char* argv [] )
{
   std::cout << frequencytable( std::vector< std::string > { "AA", "aA", "Aa", "this", "THIS" } );

   //case_insensitive_cmp c;
   //std::cout << c( "a", "A" ) << c( "a","b" ) << c( "A", "b" ) << "\n";

   //case_insensitive_hash h;
   //std::cout << h( "xxx" ) << " " << h( "XXX" ) << "\n";
   //std::cout << h( "Abc" ) << " " << h( "abC" ) << "\n";

   //case_insensitive_equality e;
   //std::cout << e( "xxx", "XXX" ) << "\n";


   return 0;
}



