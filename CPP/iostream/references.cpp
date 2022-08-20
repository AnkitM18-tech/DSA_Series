#include <iostream>

// void work(int x) {   //pass by value
// 	x++;
// }

void work(int &x) {
	x++;
}

int main() {
	int a = 10;
	int &b = a;  // creating a reference
	int c = 100;

	std::cout << a << " " << b << std::endl;  // adding & bwfore variable will return address of that variable
	// std::cout << &a << " " << &b << std::endl;
	// b = c;
	work(a);
	std::cout << a << " " << b << std::endl;
	// std::cout << &a << std::endl << &b << std::endl;
	return 0;
}