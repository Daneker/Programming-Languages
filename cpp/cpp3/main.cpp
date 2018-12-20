
#include <iostream>
#include <vector>
#include "string.h"

int main( int argc, char* argv [ ] )
{

string have = "have";
string nice = " nice ";
std::cout << have + string(" a") + nice + string("day") << "\n";


std::vector<int> a = {1,2,3};
int x = 5;
auto ddd = a.insert(a.begin(), 6);
std::cout << *ddd << std::endl;

   /* string s1 = "Daneker";
   string s2 = "hallo";
    //s1.push_back(", " + s1);
    //std::cout << s1 << std::endl;
    s1 = (string("hallooo ") + string("a"));
    //s1 = ("hallooo " + "dkddk");
/*
    std::swap( s1, s2 );
    std::cout << "\n";
    std::cout << ( s1 + ", " + s2 ) << "\n";
    std::cout << "\n";
    std::cout << string( "this is a string" ) << "\n";
    std::cout << "\n";
    s2 = ( s1 + "!" );
*/

    /*string zz = "zz";
    std::cout << "before:\n";
    string bc = string("b") + string("c");
    string max = greater( greater( "aa", string("b") + string("c") ),
                          greater( zz, string("cc")));
    std::cout << "after:\n";
    std::cout << "max = " << max << "\n";*/
	std::cout<<"--------------------------------------"<<"\n";
				string s1 = "d";
				s1 = string("d"); 
}

























/*std::map<std::string, int, map_cmp> map = {{"A", 1},{"B", 2},{"C", 3}};

for(auto p = map.begin(); p != map.end(); ++p){	
				std::cout<< p->first;
				std::cout<< p->second;
}


for(auto const& p: map){
				std::cout<<p.first;
				std::cout<<p.second;
}




for(const int& p: a){
				std::cout<<p;
}

for(int p: a)
for(int &p : a)
for(auto p : a)

auto k = map.insert({"C", 3});
std::cout<<k.first -> first << "\n";
std::cout<<k.first -> second << "\n";
std::cout<<k.second<<"\n";

size_t i = map.erase("C");
map.erase(k.first);

auto dd = map.find("A");*/

//
