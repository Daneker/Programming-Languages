#include <fstream>
#include <iostream>

#include "vectortest.h"
#include "map.h"


int main( int argc, char* argv [] )

{

				std::map<std::string, int> map = {{"A", 1},{"B", 2},{"C", 3}};

for(auto p = map.begin(); p != map.end(); ++p){	
				std::cout<< p->first<<"\n";
				std::cout<< p->second<<"\n";
}


for(auto & p: map){
				p.second = 2332;
				std::cout<<"AAA"<<p.first<<"\n";
				std::cout<<"SSS"<<p.second<<"\n";
}


std::vector<int> a = {1,2,3};

for(const int& p: a){
				std::cout<<p;
}
    std::vector<std::string> v = {"AA", "aA", "Aa", "this", "THIS"};
    std::cout << v << "\n";

    std::cout << frequencytable( v ) << "\n";

    case_insensitive_cmp c;
    std::cout << c( "a", "A" ) << c( "a","b" ) << c( "A", "b" ) << "\n\n";

    case_insensitive_hash h;
    std::cout << h( "xxx" ) << " " << h( "XXX" ) << "\n";
    std::cout << h( "Abc" ) << " " << h( "abC" ) << "\n\n";
    // Hash value should be case insensitive.

    case_insensitive_equality e;
    std::cout << e( "xxx", "XXX" ) << "\n\n";

    std::ifstream book{ "book.txt" };
    std::vector< std::string > bookVect = vectortest::readfile(book);

    std::unordered_map<std::string, unsigned int, case_insensitive_hash, case_insensitive_equality> 
					bookMap = hashed_frequencytable(bookVect);
    
    //for( const auto& s : bookVect )        std::cout << s << "\n";

    //for( const auto& p : bookMap )        std::cout << p. first << "    " << p. second << "\n";


    std::cout << "Magnus: " << bookMap["magnus"] << "\n";
    std::cout<< "Hominum: " << bookMap["hominum"] << "\n";
    std::cout<< "Memoria: " << bookMap["memoria"] << "\n";
    
    std::map<std::string, unsigned int, case_insensitive_cmp> freqWord = frequencytable( bookVect );
    std::cout << "The most frequent word: \"" << find(freqWord) << "\"\n";
std::cout<< "et: " << bookMap["et"] << "\n";

    return 0;
}
