
#ifndef STRING_INCLUDED 
#define STRING_INCLUDED 1

#include <iostream> 
#include <cstring>

class string;
std::ostream& operator << ( std::ostream&, const string& );

// p is always allocated, and len is the size of the string.
struct string
{
   size_t len;
   char *p; 

   // Default constructor
   string( )
      : len{0},
        p{nullptr}
   {
      std::cout << "this is the default constructor\n";
   }

   string( const char* c )
      : len{ strlen(c) },
        p{ new char[ len ] }
   {
      for( size_t i = 0; i < len; ++ i )
         p[i] = c[i];

      std::cout << "constructor: " << c << "\n";
   }

   string( const string& s )
      : len{ s. len },
        p{ new char[ len ] } 
   {
      for( size_t i = 0; i < len; ++ i )
         p[i] = s.p[i];
  
      std::cout << "copy constructor: " << s << "\n";
   }

   string& operator = ( const string& s )
   {
      // Not only for efficiency, but also for assignment:
      if( len != s. len )
      {
         delete[] p;
         p = new char[ s. len ];
         len = s. len; 
      }
      for( size_t i = 0; i != len; ++ i )
         p[i] = s.p[i];

      std::cout << "assignment operator: " << s << "\n";
      return *this;
   }

   string( string&& s ) noexcept
	: len{ s.len },
	  p{ s.p }
   { 
       s.len = 0; 
       s.p = nullptr; 
       std::cout << "moving constructor: " << p << "\n";
   }

   const string& operator = ( string&& s ) noexcept
   {
       std::swap( p, s.p );
       std::swap( len, s.len );
       std::cout << "moving assignment: " << p << "\n";
       return *this;
   }

   ~string( )
   {
      std::cout << "its the destructor\n";

      delete[] p; 
   }

   string& operator += ( char c );

   void push_back( const string& s );
   
   char operator [] ( size_t i ) const { 
	 //std::cout<<"For const is called"<<"\n";
	 return p[i]; 
	}
   char& operator [] ( size_t i ) { 
	  //std::cout<<"For non const is called"<<"\n";
	  return p[i]; }

   size_t size( ) const { return len; }

   using iterator = char* ;
   using const_iterator = const char* ;
   const_iterator begin( ) const { return p; }
   const_iterator end( ) const { return p + len; }
   iterator begin( ) { return p; }
   iterator end( ) { return p + len; }  

};

const string& greater( const string& s1, const string& s2 );
string&& greater( string&& s1, string&& s2 );

string& operator += ( string& s1, const string& s2 );

std::ostream& operator << ( std::ostream& out, const string& s );

//string operator + ( string s1, const string& s2 );

string operator + ( const string& s1, const string& s2 );

string operator + ( string&& s1, const string& s2 );

bool operator == ( const string& s1, const string& s2 );

bool operator < ( const string& s1, const string& s2 );

inline bool operator != ( const string& s1, const string& s2 )
{
   return !(s1 == s2);
}

inline bool operator > ( const string& s1, const string& s2 )
{
   return (s2 < s1);
};
inline bool operator <= ( const string& s1, const string& s2 )
{
   return !(s1 > s2);
}
inline bool operator >= ( const string& s1, const string& s2 )
{
   return !(s1 < s2);
}
#endif



