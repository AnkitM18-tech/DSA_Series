#include<bits/stdc++.h>
using namespace std;

void printBinary(int num) {
	for (int i = 10; i >= 0; --i) {
		cout << ((num >> i) & 1);
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 16;
	// Check Power of 2
	if (n & (n - 1)) {
		cout << "Not Power of 2" << endl;
	} else {
		cout << "Power of 2" << endl;
	}
	cout << (n & (n - 1)) << endl;
	// If this is true i.e. non-zero, then it is not 2's power, if it is 0, then it is 2's power.
}

/*
1.Odd & Even Check
n&1 = 1(True) => odd else even
it is faster than n%2, % and / operators are slow in comparison to bit manipulation

	for (int i = 0; i < 8; ++i) {
		printBinary(i);
		if (i & 1) {
			cout << "Odd\n";
		} else {
			cout << "Even\n";
		}
	}

2.Multiply and Divide by 2 - bit manipulation is fast

	int n = 5;
	// Divide by 2 -> right shift 1 bit
	cout << (n >> 1) << endl;
	// Multiply by 2 -> left shift 1 bit
	cout << (n << 1) << endl;

	can be used as (hi+lo) >> 1 = (hi+lo) / 2
	5 = 1 0 1 -> 1 0 -> (2^2*1 + 2^1*0 + 2^0*1) / 2
	5 = 1 0 1 -> 1 0 1 0 -> (2^2*1 + 2^1*0 + 2^0*1) * 2

3.Uppercase to Lowercase and vice versa

	for (char c = 'A'; c <= 'E'; ++c) {
		cout << c << endl;
		printBinary(int(c));
	}

	for (char c = 'a'; c <= 'e'; ++c) {
		cout << c << endl;
		printBinary(int(c));
	}
	// Uppercase to Lowercase set the 5th bit
	char A = 'A';
	char a = A | (1 << 5);
	cout << a << endl;
	// Lowercase to Uppercase unset the 5th bit
	char r_a = 'a';
	char r_A = (a & ~(1 << 5));
	cout << r_A << endl;

	1<<5 -> ' ' ASCII value
	printBinary('_'); // ~(1<<5) no corresponding ascii character - binary -> 00001011111 AND with the lowercase characters to get uppercase
	cout << char(1 << 5) << endl; // ' '
	// OR with ' ' -> lowercase
	cout << char('C' | ' ') << endl;
	// AND with ~' ' -> uppercase
	cout << char('c' & ~(' ')) << endl;
	// AND with '_' -> uppercase
	cout << char('c' & '_') << endl;

4.Clear LSBs upto ith bit

	printBinary(59);
	// 00000111011 -> clear LSB's upto 4(i)th bit -> 00000100000
	// 11111100000 -> inverse of 00000011111 -> we can get this by subtracting 1 from 00000100000. -> -1

	we need AND of 00000111011 and 11111100000,
	we will get 11111100000 by inverting (~) 00000011111, this we will get by 00000100000 - 1 =>  (59 & (~((1 << (4 + 1)) - 1)))

	printBinary(59);
	int a = 59;
	// 00000111011 -> clear LSB's upto 4th bit
	int i = 4;
	int b = (a & (~((1 << (i + 1)) - 1)));
	printBinary(b);

5.Clear MSBs upto ith bit

	// 00000111011 -> clear MSB's upto 3rd bit -> 00000001011
	i = 3;
	int c = (a & (1 << (i + 1)) - 1);
	printBinary(c);

	we need AND of 00000111011 and 00000001111,
	we will get 00000001111 by 00000010000 - 1 =>  (59 & (1 << (3 + 1)) - 1)

6.Check Power of 2

	int n = 15;
	// Check Power of 2
	cout << (n & (n - 1)) << endl;
	// If this is true i.e. non-zero, then it is not 2's power, if it is 0, then it is 2's power.

	int n = 16;
	// Check Power of 2
	if (n & (n - 1)) {
		cout << "Not Power of 2" << endl;
	} else {
		cout << "Power of 2" << endl;
	}
	cout << (n & (n - 1)) << endl;
	// If this is true i.e. non-zero, then it is not 2's power, if it is 0, then it is 2's power.

	power of 2 => only 1 bit is set =>
	00010000000, when we subtract 1 =>
	00001111111 => by AND op we get 0.

*/