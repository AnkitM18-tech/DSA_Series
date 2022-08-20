#include<bits/stdc++.h>
using namespace std;


int main() {

}

//The process in which a function calls itself. -> Recursion

// TRUST -> mathematical induction -> if it is correct for a small value, it will be correct for larger values as well. First write base case and prove for small value, then if it is correct we can proceed further.

/*
	//TRUST the function
	//prints: hello n times
	//VERY IMPORTANT: Base cases, without this every program will run infinitely.

	void say_hello(int n) {
		if (n == 0) { // Stopping case or base case
			return; //STOPPED
		}
		cout << "hello\n"; // printed once already
		say_hello(n - 1); // goes infinitely, if no base case, n-1 more times here with base case
	}
*/

/*
	TRUST the function -> Recursive Leap of Faith
	prints:
	hello 1
	hello 2
	hello 3
	....
	hello n-1
	hello n

	void say_hello(int n) {
		if (n == 0) {
			return;
		}
		say_hello(n - 1); // print first n-1 lines
		cout << "hello " << n << "\n";
	}
*/

/*
	//return 1 + 2 + 3 + 4 +....+ n-1 + n

	int sum_n(int n) {
		if (n == 0) {
			return 0;
		}
		int left_part = sum_n(n - 1);
		return left_part + n ;
	}
*/

/*
	returns 1 + 2 + 3 + 4 if n = 1234
	123 4 -> returns sum_digits(123) + 4
	123 -> 12 3
	12 -> 1 2
	1 -> 0 1

	int sum_digits(int n) {
		if (n == 0) {
			return 0;
		}
		int last_digit = n % 10;
		int remaining_part = n / 10;
		cout << remaining_part << " " << last_digit << "\n";
		return sum_digits(remaining_part) + last_digit;
	}
*/

/*
	returns n! of a number, if n=5, then returns 1 * 2 * 3 * 4 * 5 = 120
	(1 * 2 * 3 * 4) * 5 -> factorial(n-1) * n

	int factorial(int n) {
		if ( n == 0) {
			return 1;
		}
		int left_part = factorial(n - 1);
		return left_part * n;
	}
*/

/*
	1
	1 2
	1 2 3
	1 2 3 4
	.....
	1 2 3 4 5 ... n-1
	1 2 3 4 5 ... n-1 n

	void pattern_print(int n) {
		if (n == 0) {
			return;
		}
		pattern_print(n - 1);
		for (int i = 1; i <= n; i++) {
			cout << i << " ";
		}
		cout << "\n";
	}
*/

/*
	1 2 3 4 5 ... n-1 n
	1 2 3 4 5 ... n-1
	.....
	1 2 3 4
	1 2 3
	1 2
	1

	void pattern_print_reverse(int n) {
		if (n == 0) {
			return;
		}
		for ( int i = 1; i <= n; i++) {
			cout << i << " ";
		}
		cout << "\n";
		pattern_print_reverse(n - 1);
	}
*/

/*
	1 2 3 4 5 ... n-1 n
	1 2 3 4 5 ... n-1
	.....
	1 2 3 4
	1 2 3
	1 2
	1
	1 2
	1 2 3
	1 2 3 4
	.....
	1 2 3 4 5 ... n-1
	1 2 3 4 5 ... n-1 n

	void print_pattern_full(int n) {
		if (n == 1) {
			cout << 1 << "\n";
			return;
		}
		for (int i = 1; i <= n; i++) {
			cout << i << " ";
		}
		cout << "\n";

		print_pattern_full(n - 1);

		for (int i = 1; i <= n; i++) {
			cout << i << " ";
		}
		cout << "\n";
	}
*/

/*
	1,2,3,4,5,6,7,8,9,10,11,... -> Numbering
	0,1,1,2,3,5,8,13,21,34,55,... -> Terms

	f8 = f7 + f6 -> f(n) = f(n-1) + f(n-2) -> recurrence relation

	int fibonacci_sequence(int n) {
		if (n == 1) {
			return 0;
		}
		if (n == 2) {
			return 1;
		}
		return fibonacci_sequence(n - 1) + fibonacci_sequence(n - 2);
	}
*/

/*
	Time Complexity ->
	sum_n(n) -> n + sum_n(n-1) -> n-1 + sum_n(n-2)
	sum_n(3) -> 3 + sum_n(2) -> 2 + sum_n(1) -> 1 + sum_n(0) -> 0
	Time Complexity -> O(n) -> Linear -> 3,2,1,0 took constant time
	where as sum_n(-) took linear time.-> number of steps

	fibonacci(n) -> fibonacci(n-1) + fibonacci(n-2)
	fibonacci(n-1) -> fibonacci(n-2) + fibonacci(n-3) -> likewise it goes on.
	f(4)-> f(3) + f(2) -> f(3) -> f(2) + f(1) < f(4) -> f(3) + f(3) -> f(2) + f(2) -> The right side is number n -> 2^n levels.
	So, left side < 2^n -> left side < O(2^n)
	With recursion fibonacci works in exponential time.

	Pattern printing ->
	p(5) -> p(4) + 5 operations[because of loops]
	p(4) -> p(3) + 4 operations .. likewise
	It takes 1 + 2 + 3 ... + n -> O(n^2)
*/

/*
	Internal working of Recursion
	sum_digits(8975) -> There is an internal stack in computer.
	When a function is called whatever internal variable it has they are pushed into the stack.
	stack -> 8975
	sum_digits(897) + 5
	stack -> 8975
			897
			89
			8
	then the values are returned and we get our answers.
	Sometimes when an infinite loop runs, it gives us stackoverflow error. The stack is full and we can't fill it further.
*/