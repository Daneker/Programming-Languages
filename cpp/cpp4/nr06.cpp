
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <map>
#include "listtest.h"
#include "vectortest.h"
#include "timer.h"

std::list< std::string > convertToList( std::vector< std::string > vect)
{
   std::list< std::string > list;
   while( vect. begin( ) != vect. end( ) ) 
   {
      list.push_front( vect.back( ) );
      vect.pop_back( );
   } 
   std::cout << vect.capacity() <<"\n";
   return list;
}

int main( int argc, char* argv [] )
{
   
   std::vector< std::string > vect = {"as", "aa", "dj", "df","as", "aa", "dj", "df"};
   std::list< std::string > list;
   list=convertToList(vect);
//vectortest
   /*std::vector< std::string > vect;
   std::ifstream input{ "Inputfile.txt" };
   vect = vectortest::readfile(input);
   std::cout << vect << "\n";
   vect.clear();*/
#if 0
   vect = vectortest::randomstrings(10, 3);
   //std::cout << vect << "\n\n";
   vect.clear();

//listtest
   std::list< std::string > list;
   list.insert(list.end(), "hey");
   list.insert(list.begin(), "hi");
   list.insert(list.end(), "hello");
   //std::cout << list << "\n\n";
   list.clear();

//convertToList
   vect = vectortest::randomstrings(1000, 100);
   list = convertToList(vect);
   //std::cout << list << "\n\n";

//vect performance
   auto vect0 = vect;
   //std::cout << vect0 << "\n";
   {
       timer t("sort_assign: ", std::cout);
       vectortest::sort_assign(vect0);
   }
   //std::cout << vect0 << "\n\n";

   auto vect1 = vect;
   {
       timer t("sort_move: ", std::cout);
       vectortest::sort_move(vect1);
   }

   auto vect2 = vect;
   {
       timer t("sort_std: ", std::cout);
       vectortest::sort_std(vect2);
   }

//list performance

   auto list1 = list;
   {
       timer t("sort_assign: ", std::cout);
       listtest::sort_move(list1);
   }

   auto list2 = list;
   {
       timer t("sort_move: ", std::cout);
       listtest::sort_move(list2);
   }
#endif

   return 0;
}



