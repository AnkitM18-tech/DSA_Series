#include<iostream>
#include<array>

void print_stl_array(std::array<int, 20> array, int size) {
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << "\t";
	}
	std::cout << "\n";
}

int main() {
	std::array<int, 20> data = {1, 2, 3};
	print_stl_array(data, 3);
	return 0;
}

// STL arrays and Vectors are passed by value to functions and can't be changed directly in the function, but C style arrays are passed by reference, so they can be changed directly. Also C- style arrays don't remember their size so we have to enter their size manually as additional argument. In STL arrays and Vectors we can assign them directly to other variables of the same type directly, but in C style arrays we have to iterate through the array and assign one by one. there is a size() method in STL arrays and Vectors which can be used to find size of the variable but C style arrays we have to calculate manually. Pass by value --> copy of variable , Pass by reference --> direct access to main variable.