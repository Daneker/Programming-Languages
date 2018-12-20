#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <ctype.h>

struct case_insensitive_cmp
{
bool operator( ) ( const std::string& s1, const std::string& s2 ) const;
// Return true if s1 < s2, ignoring case of the letters.
};

struct case_insensitive_hash
{
    size_t operator ( ) ( const std::string& ) const;
};

struct case_insensitive_equality
{
    bool operator ( ) ( const std::string& , const std::string& ) const;
};

std::string lowerCase ( std::string s );


    std::map< std::string, unsigned int, case_insensitive_cmp> frequencytable( const std::vector< std::string > & text);

    std::unordered_map< std::string, unsigned int, case_insensitive_hash, case_insensitive_equality >
    hashed_frequencytable ( const std::vector< std::string > & text );

    std::string find( std::map< std::string, unsigned int, case_insensitive_cmp>  mMap);


std::ostream& operator << ( std::ostream& stream, const std::map< std::string, unsigned int , case_insensitive_cmp> & );




