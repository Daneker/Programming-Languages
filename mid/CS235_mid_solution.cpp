
#include <string>
#include <iostream> 
#include <list>
#include <map>

// This is first part, about using list for string:

bool operator < ( const std::list<char> & l1, const std::list<char> & l2 )
{
   auto p1 = l1. begin( );
   auto p2 = l2. begin( );

   // Cannot use < here:
   while( p1 != l1. end( ) && p2 != l2. end( ))
   {
      if( *p1 < *p2 ) return true;
      if( *p1 > *p2 ) return false;
      ++ p1; ++ p2;
   }

   return l1. size( ) < l2. size( );
}

bool operator == ( const std::list<char> & l1, const std::list<char> & l2 )
{
   if( l1. size( ) != l2. size( )) return false;
   
   auto p1 = l1. begin( );
   auto p2 = l2. begin( );
   while( p1 != l1. end( ))
   {
      if( *p1 != *p2 ) return false; 
      ++ p1; ++ p2;
   }
   return true;
}

// 1d:

inline bool operator > ( const std::list<char> & l1, const std::list<char> & l2 )
{
   return l2 < l1;
}

inline bool operator != ( const std::list<char> & l1, const std::list<char> & l2 )
{
   return !(l1==l2);
}

inline bool operator <= ( const std::list<char> & l1, const std::list<char> & l2 )
{
   return !( l1 > l2 );
}

inline bool operator >= ( const std::list<char> & l1, const std::list<char> & l2 )
{
   return !( l1 < l2 );
}

const std::list<char> & 
operator += ( std::list<char> & s1, const std::list<char> & s2 )
{
   size_t s = s2. size( );

   auto p = s2. begin( );
   while(s)
   {
      s1. push_back( *p++ );
      -- s;
   }
   return s1;
}

std::list<char>
operator + ( std::list<char> s1, const std::list<char> & s2 )
{
   s1 += s2;
   return s1;
}

std::ostream& operator << ( std::ostream& out, const std::list<char> & l )
{
   for( auto c : l ) 
      out << c;
   return out;
}

  
struct tree_node
{
   std::string key;
   std::string value; 

   tree_node* left;
   tree_node* right;

   tree_node( const std::string& key, const std::string& value,
              tree_node* left, tree_node* right )
      : key{ key }, value{ value },
        left{ left }, right{ right }
   { }
   
};


// answer to 5B:

void destroy( tree_node* n )
{
   if( n -> left ) destroy( n -> left );
   if( n -> right ) destroy( n -> right );
   delete n;
}

tree_node* copy( const tree_node* n )
{
   return new tree_node( n -> key, n -> value,
      ( n -> left ) ? copy( n -> left ) : nullptr,
      ( n -> right ) ? copy( n -> right ) : nullptr );
}

// You don't have to care about balancing the tree.

void insert( tree_node* & n, 
             const std::string& key, const std::string& value )
{
   if( !n )
      n = new tree_node( key, value, nullptr, nullptr );
   else
   {
      if( key == n -> key )
         n -> value = value;

      if( key < n -> key )
      {
         insert( n -> left, key, value );
         return;
      }

      insert( n -> right, key, value );
      return; 
   }
}

// answer to 5E:

std::string& lookup( tree_node* & n, const std::string& key )
{
   if(!n) 
   { n = new tree_node( key, std::string( ), nullptr, nullptr );
     return n -> value;
   }
   else
   {
      std::cout << "looking in " << ( n -> key ) << "\n";

      if( key == n -> key ) return n -> value;

      if( key < n -> key )
         return lookup( n -> left, key );
      else
        return lookup( n -> right, key );
   }
}

std::string find( const tree_node* n, const std::string& key )
{
   if(n)
   {
      std::cout << "looking in " << ( n -> key ) << "\n";
      if( n -> key == key ) return n -> value;
      if( n -> key > key ) return find( n -> left, key );
      return find( n -> right, key );
   }
   else
      return std::string( ); 
}

// Answer to 5C:

size_t size( const tree_node* n )
{
   if(n)
      return 1 + size( n -> left ) + size( n -> right );
   else
      return 0;
}
 
struct tree
{
   tree_node* n;

   tree( ) : n{ nullptr } { } 

   // Answers to 5a:

   tree( const tree& t )
      : n{ copy(t.n) }
   { }

   tree( tree&& t ) :
      n{ t.n }
   {
      t.n = nullptr; 
   }

   const tree& operator = ( const tree& t ) 
   {
      if( n != t.n )
      {
         destroy(n);
         n = copy(t.n);
      }
      return *this; 
   }

   const tree& operator = ( tree&& t )
   {
      std::swap( n, t.n );
      return *this;
   }

   void insert( const std::string& key, const std::string& value )
      { ::insert( n, key, value ); }

   std::string find( const std::string& key ) const
      { return ::find( n, key ); }

   std::string& operator[] ( const std::string& key )
   {
      return lookup( n, key );
   }

   size_t size( ) const
   { 
      return ::size( n );
   }
 
   ~tree( ) { destroy(n); } 
};


int main( int argc, char* argv[] )
{
   std::list<char> s1 = { 'a', 'b', 'c' };
   std::list<char> s2 = { 'd', 'e', 'f' };

   s1 += s1; s1 += s1;

   std::cout << s1 << "\n";
   std::cout << ( s2 + s1 ) << "\n";

   tree tr;
   tr. insert( "one", "eins" );
   tr. insert( "two", "zwei" );
   tr. insert( "three", "drei" );

   auto tr2 = tr;
   tr = tr2;

   tr[ "four" ] = "vier";
   std::cout << tr[ "four" ] << "\n"; 

   std::cout << tr. size( ) << "\n";
}

