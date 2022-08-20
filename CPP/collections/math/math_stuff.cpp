//Calling in main function .cpp

#include <iostream>
#include "math_utils.h"   // looks for the header file in current directory when using ""

int main() {
	std::cout << utilz::pow(3, 3) << std::endl;
	std::cout << utilz::pow(3) << std::endl;
	Rectangle rectangle;
	rectangle.length = 10;
	rectangle.width = 20;
	std::cout << utilz::area(rectangle.length, rectangle.width) << "\n";
	std::cout << utilz::area(rectangle.width) << "\n";
	std::cout << utilz::area(rectangle) << "\n";
	return 0;
}

// while compilation using -c flag will create .o file where the code will be hidden --> object file ,then we can compile them as usual.
// g++ -c .\math_stuff.cpp .\math_utils.cpp
// g++ .\math_stuff.o .\math_utils.o