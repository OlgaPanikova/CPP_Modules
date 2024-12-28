#include "whatever.hpp"

int main() {
	int x = 5, y = 10;

	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
	swap(x, y);
	std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

	std::cout << "Min of 5 and 10: " << ::min(5, 10) << std::endl;
	std::cout << "Max of 5 and 10: " << ::max(5, 10) << std::endl;

	double a = 3.14, b = 2.71;
	std::cout << "Min of 3.14 and 2.71: " << ::min(a, b) << std::endl;
	std::cout << "Max of 3.14 and 2.71: " << ::max(a, b) << std::endl;

	std::string str1 = "Hello cat";
	std::string str2 = "My name is Henry";

	std::cout << "Before swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;
	swap(str1, str2);
	std::cout << "After swap: str2 = " << str1 << ", str2 = " << str2 << std::endl;

// int a = 2;
// int b = 3;
// ::swap( a, b );
// std::cout << "a = " << a << ", b = " << b << std::endl;
// std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// std::string c = "chaine1";
// std::string d = "chaine2";
// ::swap(c, d);
// std::cout << "c = " << c << ", d = " << d << std::endl;
// std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
