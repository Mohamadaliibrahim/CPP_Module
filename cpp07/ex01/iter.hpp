#ifndef INTER_HPP
#define INTER_HPP

#include <cstddef>

template <typename T, typename F>
void    iter(T* array, size_t length, F function)
{
    for (size_t i = 0; i < length; ++i)
    {
        function(array[i]);
    }
}

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

#endif