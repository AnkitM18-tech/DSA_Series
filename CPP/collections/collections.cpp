#include <iostream>
#include <limits>

namespace utilz
{
void print_array(int array[], int size) {
	//std::cout << sizeof(array) << std::endl; //will point at the first element of the array, acts as a pointer, returns int * --> 4 bytes. to solve this problem add the size argument as well.
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << "\t";
	}

}
}


int main() {
	/*
	// int guesses[20]; statically sized --> if you don't define an array it will assign garbage values itself.
	int guesses[] = {13, 22, 87, 98, 567, 23}; //if you know data before hand, put the data here and it will make the size (number of data) + 1.
	std::cout << guesses[3] << std::endl;
	guesses[3] = 300;
	*/

	/*
	int guesses[] = {12, 34, 56, 45, 78, 98};
	int size =  sizeof(guesses) / sizeof(int);
	print_array(guesses, size);
	*/

	/*
	int num_elements = 5;
	int size = sizeof(guesses) / sizeof(int); // to get the size of array(number of elements). sizeof(guesses) gives 24 as 6*sizeof(int) -> 4 Bytes = 24 Bytes.
	std::cout << size << std::endl;
	for (int i = 0; i < num_elements; i++)
	{
		std::cout << guesses[i] << "\t";

	}
	*/
	const int SIZE = 100;  // it's better to reserve spaces if you don't know how many elements you wanna store.
	int guesses[SIZE];
	int count = 0; // to keep track of numbers entered
	for (int i = 0; i < SIZE; i++)
	{
		if (std::cin >> guesses[i]) { // returns true,  cin if input worked (stored successfully)
			//input worked
			count++;
		} else {
			//invalid input. --> work around if we want to stop entering elements in the array.
			break;
		}
	}
	utilz::print_array(guesses, count);
	std::cout << std::endl;
	std::cin.clear() ; // to make the non-working state cin to get to working. if any invalid input is entered, it's gonna stay that way, unless we clear it. so it's needed.
	std::cin.ignore(10000, '\n');  // will ignore the invalid thing entered and wait for us to enter something to store in that test variable. ignore 10000 characters.
	// better way to ignore the invalid texts entered -->
	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string test;
	std::cin >> test;
	std::cout << test << std::endl;
	return 0;
}