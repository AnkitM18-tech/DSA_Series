#include <iostream>
#include <string>

template <typename T>  // helps us to implement code for multiple datatypes without defining them.
void swap(T &a, T &b) {  // using & will pass by reference and change the original value
	T temp = a;
	a = b;
	b = temp;

	// std::cout << "a: " << a << "\tb: " << b << "\n";
}

template <typename T>
void swap(T a[], T b[], int size) {
	for (int i = 0; i < size; i++)
	{
		T temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}
/*
void swap(std::string &a, std::string &b) {
	std::string temp = a;
	a = b;
	b = temp;

	std::cout << "Name: " << a << "\tName2: " << b << "\n";
}
*/
int main() {
	const int SIZE = 6;
	int a = 10;
	int b = 20;
	swap(a, b);   // after function call the value will be same, as these are passed by value.
	std::cout << "a: " << a << "\tb: " << b << "\n";

	std::string name = "Ankit";
	std::string name2 = "Kumar";
	swap(name, name2);
	std::cout << "Name: " << name << "\tName2: " << name2 << "\n";

	int nines[] = {9, 9, 9, 9, 9, 9};
	int ones[] = {1, 1, 1, 1, 1, 1};
	for (int i = 0; i < SIZE; i++) {
		std::cout << nines[i] << " " << ones[i] << "\t";
	}
	std::cout << "\n";
	swap(nines, ones, SIZE);
	for (int i = 0; i < SIZE; i++) {
		std::cout << nines[i] << " " << ones[i] << "\t";
	}
	std::cout << "\n";
	return 0;
}