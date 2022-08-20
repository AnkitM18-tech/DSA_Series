#include <iostream>
#include <vector>

void do_something(const int array[]) {

}

void print_array(const int data[], int size) { // const modifier won't allow the function to change the original array
	for (int i = 0; i < size; i++)
	{
		// data[i]++;   if const won't be there it will increment each element in the original array
		std::cout << data[i] << "\t";
	}
	std::cout << "\n";
	do_something(data);   // will only work if the const rule is not broken, i.e the paramter contains const modifier and won't change the original array directly or indirectly. it could potentially change the original array so it will throw an error and can't call the function if const is not there.
}

int main() {

	int data[] = {1, 2, 3};
	print_array(data, 3);
	return 0;
}