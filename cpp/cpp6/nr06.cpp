#if 0
#include <fstream>
#include <iostream>

#include "listtest.h"
#include "vectortest.h"
#include "timer.h"

std::list<std::string> convertToList(std::vector<std::string> vect );

int main( int argc, char* argv [] )
{
   std::ifstream inp{ "new.txt" };
   std::cout << vectortest::readfile(inp) << "\n";   
   std::vector< std::string > vect;
   std::cout << "Here is the vector with size " << vect.size() << "\n";
   std::cout << vect << "\n";
   vect.resize(4, "so");
   std::cout << "Here is the vector with size " << vect.size() << "\n";
   std::cout << vect << "\n";

   std::list< std::string > list1;
   std::cout << "Here is the list with size " << list1.size() << "\n";
   std::cout << list1 << "\n";

   vect.clear();
   vect = vectortest::randomstrings(30000, 50);
   std::list< std::string > lst;
   lst = convertToList(vect);
   // Or use timer:

   auto t1 = std::chrono::high_resolution_clock::now( ); 
   vectortest::sort_move( vect );
   auto t2 = std::chrono::high_resolution_clock::now( );

   std::chrono::duration< double > d = ( t2 - t1 );

   std::cout << "sorting took " << d. count( ) << " seconds\n";

   auto t1 = std::chrono::high_resolution_clock::now( ); 
   vectortest::sort_assign( vect );
   auto t2 = std::chrono::high_resolution_clock::now( );
   std::chrono::duration< double > d = ( t2 - t1 );
   std::cout << "sorting took " << d. count( ) << " seconds\n";


   auto t1 = std::chrono::high_resolution_clock::now( ); 
   vectortest::sort_std( vect );
   auto t2 = std::chrono::high_resolution_clock::now( );
   std::chrono::duration< double > d = ( t2 - t1 );
   std::cout << "sorting took " << d. count( ) << " seconds\n";

   auto t1 = std::chrono::high_resolution_clock::now( ); 
   listtest::sort_move( lst );
   auto t2 = std::chrono::high_resolution_clock::now( );
   std::chrono::duration< double > d = ( t2 - t1 );
   std::cout << "sorting took " << d. count( ) << " seconds\n";


   auto t1 = std::chrono::high_resolution_clock::now( ); 
   listtest::sort_assign( lst );
   auto t2 = std::chrono::high_resolution_clock::now( );
   std::chrono::duration< double > d = ( t2 - t1 );
   std::cout << "sorting took " << d. count( ) << " seconds\n";




   return 0;
}

std::list<std::string> convertToList(std::vector<std::string> vect )
{
    std::list<std::string> list0;
    
    std::vector< std::string >::const_iterator j;

    for( j = vect.begin(); j != vect.end(); ++j)
    {
	list0.push_front (vect.back());
	vect. pop_back(); 
    }	

    return list0;
}


#endif
