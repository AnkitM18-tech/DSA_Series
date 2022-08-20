#include <iostream>
#include <vector>
#include <array>

int main() {
	// int array[] = {1, 2, 3, 4, 5, 6};
	// std::vector<int> array = {1, 2, 3, 4, 5, 6};
	std::array<int, 6> array = {1, 2, 3, 4, 5, 6};

	for (int n : array) { // only useful while using arrays and vectors in the same function not useful when passing it to another function, as normal C style arrays are passed by reference, so they can't remember their size so "range based for" can't be used in another function.
		std::cout << n << "\t";
	}
	std::cout << "\n";
}