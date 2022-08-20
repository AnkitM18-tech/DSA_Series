#include <iostream>

void change(int* x) {
	*x = 10;
}

int main() {
	int x = 50;
	change(&x);
	std::cout << x << "\n";
	return 0;
}

/*int* y = &x;   // initializing a pointer  (address)y = &x ---> *y = x(value)
x = 10;
*y = 18;  // if we change any of it, that will reflect everywhere
std::cout << &x << " " << y << std::endl;
std::cout << x << " " << *y << std::endl; // dereferencing the pointer and getting the value
int z = 5;
y = &z;
std::cout << &x << " " << y << std::endl;
std::cout << x << " " << *y << " " << z << std::endl;*/
// pointers can be re-assigned to point somewhere else (to another address), but references will point to the same area of memory(fixed).