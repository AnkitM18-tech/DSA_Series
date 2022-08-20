#include <iostream>
#include <string>

class User {
public:
	std::string name;
};

int main() {
	int *x = new int(5);
	std::cout << "The pointer " << x << " points to " << *x << "\n";
	delete x;

	// User u;
	// u.name = "Ankit Mohanty";
	User *u = new User();
	// (*u).name = "Ankit Mohanty";
	// std::cout << (*u).name << "\n";
	u->name = "Ankit";
	std::cout << u->name << "\n";
	delete u;
	return 0;
}

/*
int *x = new int(5);  // instead of stack the object is created in heap memory, we need to free it ourselves using delete keyword. and it gives a pointer.
delete x;

//Generally used with objects
User* u = new User();  // more appropriate way would be "User u;" --> new is often used in C# and Java.
(*u).name = "Ankit";  // we can use u->name shorthand
delete u;

We can use this for dynamic memory allocation. // recommended would be vector ----> dynamic array

//dynamic array initialization
int size;
cin >> size;
int *array = new int[size];
delete [] array;
return 0;

// safe alternative
std::unique_ptr<int[]> array(new int[size]); --> c++11
auto array = std::make_unique<int[]> (size); --> c++14

#include <memory> is relying library

*/