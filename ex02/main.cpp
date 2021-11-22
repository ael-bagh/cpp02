# include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
Fixed c(30);
Fixed d(2);
Fixed e(15.42f);
Fixed f(10.42f);
// ++ --
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << --a << std::endl;
std::cout << a << std::endl;
std::cout << a-- << std::endl;
std::cout << a << std::endl;
// * overload
std::cout << "b = " << b << std::endl;
// + overload
std::cout << "c + d =" << c + d << std::endl;
// toFloat
std::cout << "c to float " << c.toFloat() << std::endl;
// toInt
std::cout << "f to int" << f.toInt() << std::endl;
std::cout << "fixed c - d =" << c - d << std::endl;
std::cout << "float c * d =" << c.toFloat() * d.toFloat() << std::endl;
std::cout << "fixed c * d =" << c * d << std::endl;
std::cout << "float c / d =" << c.toFloat() / d.toFloat() << std::endl;
std::cout << "fixed c / d =" << c / d << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
std::cout << Fixed::min( a, b ) << std::endl;
return 0;
}