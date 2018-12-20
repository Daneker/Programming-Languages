#include "map.h"

bool case_insensitive_cmp::operator() (const std::string& s1, const std::string& s2) const
{
        
    for(size_t i = 0; i < s1.size() && i < s2.size(); ++ i) {
        int str1 = std::tolower(s1[i]);
        int str2 = std::tolower(s2[i]);

        if (str1 != str2)
	{
	    return str1 < str2;
	}
    }

    return s1.size() < s2.size();
}

using insensitive_map = std::map< std::string, unsigned int, case_insensitive_cmp >;
insensitive_map frequencytable(const std::vector< std::string > & text )
{
    size_t size = text.size();
    insensitive_map mMap;    

    for(size_t i = 0; i < size; i ++){
        const std::string& s = text[i];
        mMap[s]++;
    }

    return mMap;
}

std::ostream& operator << ( std::ostream& stream, const insensitive_map & freq )
{
	for (auto& iterator : freq)
	{
		stream << iterator.first << " -> " << iterator.second << "\n";
	}

	return stream;
}

size_t case_insensitive_hash::operator ( ) ( const std::string& s ) const
{

      std::string new_str = s;
      for( char& c : new_str ) c = tolower(c);
      std::hash< std::string > hash_str;
      return hash_str(new_str);
}

bool case_insensitive_equality::operator ( ) ( const std::string& s1, const std::string& s2 ) const
{
      size_t len = (s1.length() < s2.length()) ? s1.length() : s2.length();

      for(size_t i = 0; i < len; i++)  
      {
         int a = tolower(s1[i]);
         int b = tolower(s2[i]);
         if(a != b) return false;
      }
      return true;
    
}

std::unordered_map< std::string, unsigned int, case_insensitive_hash, case_insensitive_equality >
    hashed_frequencytable ( const std::vector< std::string > & text )
{
    std::unordered_map< std::string, unsigned int, case_insensitive_hash, case_insensitive_equality > result;
    size_t size = text.size();

    for( size_t i = 0; i < size; i ++ )
    {
        const std::string& temp = text[i];
        result[temp] ++;
    }
    return result;
}

std::string find( insensitive_map  mMap){
    unsigned int counter = 0;
    std::string result;

    for( insensitive_map::const_iterator iter = mMap.begin();
        iter != mMap.end(); ++ iter){
        if(iter->second > counter) {
            counter = iter->second;
            result = iter->first;
        }
    }
    return result;
}
