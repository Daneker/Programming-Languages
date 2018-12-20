
#include "string.h"

std::ostream& operator << ( std::ostream& out, const string& s )
{
   for( char c : s)
      out << c;
   return out;   // Always return the stream!
}

string& string::operator += ( char c )
{
   char* new_p = new char[len+1];
   for(size_t i = 0; i < len; i++) {
     new_p[i] = p[i];
   }

   delete[] p;

   new_p[len] = c;
   p = new_p;
   len++;
   //std::cout << "this is operator += for char\n";
   return *this;
}

void string::push_back( const string& s )
{
   size_t new_len = len + s.len;
   char* new_p = new char[new_len];
   for(size_t i = 0; i < len; i++) 
        new_p[i] = p[i];
 
   for(size_t i = 0; i < s.len; i++)
        new_p[i+len] = s.p[i];

   delete[] p;
   len = new_len;
   p = new_p;
   
}

string& operator += ( string& s1, const string& s2 )
{

//one possible solution
#if 0 
   for(size_t i = 0; i < s2.len; i++) 
   {
      char c = s2.p[i];
      std::cout << "this is a s2.p[i]" << c << "\n";
      s1 += c;
   }
   return s1;
#endif

   size_t len = s1.len + s2.len;
   char* new_p = new char[len];

   for(size_t i = 0; i < s1.len; i++) {
      new_p[i] = s1.p[i];
   }

   for(size_t i = 0; i < s2.len; i++) {
      new_p[i + s1.len] = s2.p[i];
   }

   delete[] s1.p;
   s1.len += s2.len;
   s1.p = new_p;
 
   return s1;
}

/*string operator + ( string s1, const string& s2 )
{
   std::cout << "it is operator +\n";
   return s1 += s2;  
}*/

string operator + ( const string& s1, const string& s2 )
{
   std::cout << "it is operator +\n";
   string s = s1;
   s += s2;
   return s;
}

string operator + ( string&& s1, const string& s2 )
{
  std::cout << "it is operator ++++\n";
  s1 += s2;
  return std::move(s1);  
}

bool operator == ( const string& s1, const string& s2 )
{
   if(s1.len != s2.len) return false;
   
   size_t len = s1.len;
   size_t i = 0;

   while((i < len) && (s1[i] == s2[i])) i++;

   return (i == len);
}

bool operator < ( const string& s1, const string& s2 )
{
   size_t len = (s1.len < s2.len) ? s1.len : s2.len;
   size_t i = 0;
   
   while((i < len) && (s1[i] == s2[i])) i++;
   
   if(i == len) { 
       return (s1.len < s2.len);
   }

   if(s1[i] != s2[i]) {
       return (s1[i] < s2[i]);
   }
   
   //works without the following as well
   return s1[i] < s2[i]; 
}

const string& greater( const string& s1, const string& s2 )
{
   if(s1 > s2) {
      std::cout << "reference greater: " << s1 << " " << s2 << "\n";
      return s1;
   } else {
      std::cout << "reference greater: " << s2 << " " << s1 << "\n";
      return s2;

   }
}

string&& greater( string&& s1, string&& s2 ) 
{
   if(s1 > s2) {
      std::cout << "moving greater: " << s1 << " " << s2 << "\n";
      return std::move(s1);
   } else {
      std::cout << "moving greater: " << s2 << " " << s1 << "\n";
      return std::move(s2);
   }    
}


