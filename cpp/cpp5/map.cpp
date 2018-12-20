#include "map.h"


struct case_insensitive_cmp
{
   // Return true if s1 < s2, ignoring case of the letters.
   bool operator( ) ( const std::string& s1, const std::string& s2 ) const
   {
      size_t len = (s1.length() < s2.length()) ? s1.length() : s2.length();
        
      for(size_t i = 0; i < len; i++) 
      {
         int a = tolower(s1[i]);
         int b = tolower(s2[i]);
         if(a != b) return a < b;;
      }

      return s1.length() < s2.length();
   }
};
struct case_insensitive_hash
{
   size_t operator ( ) ( const std::string& s ) const
   {
      std::string new_str = s;
      for( char& c : new_str ) c = tolower(c);
      std::hash< std::string > hash_str;
      //std::cout << hash_str(new_str) << std::endl;
      return hash_str(new_str);
   }
};
struct case_insensitive_equality
{
   bool operator ( ) ( const std::string& s1, const std::string& s2 ) const
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
};

std::map< std::string, unsigned int, case_insensitive_cmp > frequencytable(
          const std::vector< std::string > & text )
{
   std::map< std::string, unsigned int, case_insensitive_cmp > count;
   for(const std::string & str : text) 
   {
      count[str]++;
   }
   return count;	
}

std::unordered_map< std::string, unsigned int, 
			case_insensitive_hash, case_insensitive_equality >
			hashed_frequencytable( const std::vector< std::string > & text )
{
   std::unordered_map< std::string, unsigned int, case_insensitive_cmp > count;
   for(const std::string & str : text) 
   {
      count[str]++;
   }
   return count;
}

std::string find_word( insensitive_map  mMap){
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

std::ostream&
operator << ( std::ostream& out,
const std::map< std::string, unsigned int, case_insensitive_cmp > & freq )
{
   for(auto & p : freq)
      out << p.first << " - " << p.second << "\n";
   return out;
}

std::ostream&
operator << ( std::ostream& out,
const std::unordered_map< std::string, unsigned int, case_insensitive_cmp > & freq )
{
   for(auto & p : freq)
      out << p.first << " - " << p.second << "\n";
   return out;
}

