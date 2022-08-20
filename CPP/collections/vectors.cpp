#include <iostream>
#include <vector>

void print_vector(std::vector <int> & data) { // by adding &, it will share the same memory address with the main vector. It is called pass by reference --> when you want to change the main vector in this function. Without & it is pass by value --> which doesn't change the main vector.
	data.push_back(12);
	for (int i = 0; i < data.size(); i++)
	{
		std::cout << data[i] << "\t";
	}
	std::cout << "\n";
}

int main() {
	//vectors are more flexible than arrays, if the number of elements exceeds the size allocated then it will reallocate new memory and shift all the values there behind the scenes. So we can add more values in it, without any worries. Vectors are dynamic in size, they know there size, we don't need to calculate it ourselves like in arrays.
	std::vector <int> data = {1, 2, 3};
	print_vector(data);
	print_vector(data);
	print_vector(data);
	print_vector(data);
	// data.push_back(12);
	// std::cout << data[3] << std::endl;
	// //data.size() - 1 --> last element index
	// data.pop_back(); // removes the last element
	// std::cout << data.size() << std::endl;
	return 0;
}