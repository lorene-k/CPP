/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/29 18:45:49 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// ****************************************************************** MY MAIN //
// template <typename T>
// void printElement(T const &elem)
// {
//     std::cout << elem << " ";
// }

// int main()
// {
//     std::cout << MAUVE << "\n===== INT TESTS =====" << RESET << std::endl;
//     int intArray[] = {1, 2, 3, 4, 5};
//     int intLen = sizeof(intArray) / sizeof(intArray[0]);

//     iter(intArray, intLen, printElement<int>);
//     std::cout << std::endl;

//     std::cout << MAUVE << "\n===== STRING TESTS =====" << RESET << std::endl;
//     std::string strArray[] = {"I", "love", "green", "apples"};
//     int strLen = sizeof(strArray) / sizeof(strArray[0]);

//     iter(strArray, strLen, printElement<std::string>);
//     std::cout << std::endl << std::endl;

//     return (0);
// }

// ************************************************************ ATTACHED MAIN //
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

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}
