#include "Template.hpp"

/* int main()
{
	int a = 2;
	int b = 3;
	double c = 2.5;
	double d = 3.5;

	std::cout << "a: " << a << " b: " << b << std::endl;
	swap(a, b);
	std::cout << "a: " << a << " b: " << b << std::endl;

	std::cout << "min: " << min(a, b) << std::endl;
	std::cout << "max: " << max(a, b) << std::endl;

	std::cout << "c: " << c << " d: " << d << std::endl;
	swap(c, d);
	std::cout << "c: " << c << " d: " << d << std::endl;
	return (0);
} */

int main( void )
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}