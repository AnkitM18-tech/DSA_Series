#include<bits/stdc++.h>
using namespace std;
// const int N = 1e7; // will run without any problem
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a;
	cin >> a;
	cout << a * a;
	// const int N = 1e7; // segamentation fault
	// const int N = 1e5; // will run without segmentation fault
	// int a[N];
	// a[0] = 1;
	// cout << a[0];
}

// C++ Memory Structure
/*
	kernel space -> user can not read or write to these addresses, doing so will result in segmentation fault.

	Stack(grows down) -> has a size limit(eg 8mb) -> :Local variables are initialized and stored here -> has memory limitations -> array size > 8 MB -> Stack Overflow

	Memory segment -> File mappings and anonymous mappings

	Heap

	BSS Segment -> uninitialized static variable
	DATA Segment -> Static variables initialized by user -> Global variables are stored. -> as such no memory limit, so no segmentation fault.
	Text Segment -> Stores the binary image of the process

	void increment(int &n) { // pass by reference that means the value changed inside the function will be reflected outside the function(actual variable is passed). In pass by value only a copy of the variable will be passed and won't get changed outside the function.
		n++;
	}

	arrays are always passed as references to a function. Other datatypes are passed by value.

	In CP programs declare arrays globally, so that we can use them directly in functions. As when declaring 2D arrays it is compulsory to enter the 2nd argument(Columns) and we can't enter/pass the no. of rows and columns defined inside the main function and access them it is not always supported by compiler.

	From good code point of view it is not correct. we need to pass the arrays, not globally declare.

	Pointers =>
	int x = 4;   1 2 3 4 => 4 let's assume int takes 4 bytes => 4 is stored in the continuous address 1 2 3 4.
	int *p_x; //data type will be the same as the variable we want to store in that pointer variable.
	p_x = &x; // using & we store the address of x into p_x; pointers are used to store addresses of variables.
	cout << *p_x; p_x = 1 (first address location among the 4 bytes allocated to int)
	we can access the values inside pointers using *p_x;
	*p_x = 5; the value of x variable will be changed to 5.
	p_x = p_x + 1; p_x will become 5, size of data type pointer will get added . p_x was from 1 - 4 , now it is modified to 5; p_x will go to the next block.
	Allocation of array is continuous. If we define something like int a[10], then continuous allocation of 40(10 * 4 Bytes) bytes will occur in the memory.
	cout << a; -> address of first block and cout << * a; // prints the first block value a[0]
	a <-> &a[0] => both are same , a+1 => &(a+1) , &(a+1) => &a[1], *(a+1) -> a[1]
	int *p; -> stores address of an integer; int **pp; -> stores address of the integer pointer => double pointer
	int x = 4;
	p = &x;
	pp = &p;
	*pp -> p's value -> &x => **pp -> * (&x(p)) = 4
	Passing pointer to function ->
	void increment(int *x) {
		(*x)++; // to increment the value
	}
	int main() {
		int a=4;
		increment(&a); // passing address/pointer
	}

	string s;

	for (int i = 0; i < n; ++i) {
		s = s + 'a'; // Time Complexity -> O(s.size()) makes a copy of s , then add 'a' and stores the value in s. Complexity increases with increasing i.
	}

	for (int i = 0; i < n; ++i) {
		s = s.push_back(a); // Time Complexity -> O(1) takes constant time
	}

*/
