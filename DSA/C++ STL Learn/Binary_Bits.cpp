#include<bits/stdc++.h>
using namespace std;

// Shifting the ith bit to )th pos and then performing AND op with 1.
void printBinary(int num) {
	for (int i = 10; i >= 0; --i) {
		cout << ((num >> i) & 1);
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*
	cout << INT_MAX << endl;
	int a = (1LL << 31) - 1; // signed integer - 1 bit is reserved for sign int(pos/neg), that's why 32 bits can not be stored in signed int
	cout << a << endl;
	unsigned int b = (1LL << 32) - 1;
	cout << b << endl;
	*/
	printBinary(9);
	// cout << (9 >> 1) << endl;
	int a = 9;
	int i = 3;
	if ((a & (1 << i)) != 0) {
		cout << "Set" << endl;
	} else {
		cout << "Not Set" << endl;
	}
	// Set Bit ith bit = 1
	printBinary(a | (1 << 1));
	// Unset Bit ith bit = 3, AND op with a binary having unset ith bit
	printBinary(a & ~(1 << 3));
	// cout << ((a >> 3) & 1) << endl;
	// Toggle the ith bit, XOR op with a binary having ith bit set
	printBinary(a ^ (1 << 2));
	printBinary(a ^ (1 << 3));
	// Counting the set bits
	int cnt = 0;
	for (int i = 31; i >= 0; --i) {
		if ((a & (1 << i)) != 0) {
			cnt++;
		}
	}
	cout << cnt << endl;
	// In built function to find set bits int, if we try for long long then error will come.
	cout << __builtin_popcount(a) << endl;
	// In built function to find set bits long long
	cout << __builtin_popcountll((1LL << 35) - 1) << endl; // 35 set bits, after subtracting 100--36 0's -1
}

/*

XOR -> 0 1 = 1 | 1 0 = 1
1 << 0 = 1 = 2^0
1 << 1 = 1 0 = 2^1
1 << 2 = 1 0 0 = 2^2
------ 1 << n = 2^n

1 << 32 = 1 is integer, calculation is in long long , 33 bits => error
1LL << 32 => overflow => -1 -> signed integer
1LL << 31 -1 => INT_MAX - signed int => -2^31 to 2^31 - 1 range
unisigned integer can store 1LL << 32 -1 => 0 to 2^32-1 range

*/

/*
	LSB = least significant bit = left most bit
	MSB = most significant bit = Nth bit
	set bit = 1
	unset bit = 1

	which ever bit we need to inspect, we take a binary in which only that bit is set and perform a AND operation b/w those.

		2 1 0
	5 = 1 0 1 , suppose we need to inspect 1st bit whether it is set or not, so we take a binary in which 1st bit is set only = 0 1 0

	AND ops = 1 0 1 & 0 1 0 = 0 0 0 => 1st bit is not set. if it were 1 then only we can conclude that bit is set.

	ith bit is set or not is determined by setting only the ith bit in a binary and finding their AND operation

	1 << i is how we will find that ith bit set binary
	1 << 0 = 1
	1 << 1 = 0 1 0
	1 << 2 = 0 0 1 0 0

	if we subtract 1 from the left shifted 1 binary, we will get a binary with all set bits having n-1 bits. (1 0 0 0 - 1 = 1 1 1)

	2 ke power wale number ke pehle waale saare binary numbers ke all bits are set. 3,7,15,31
*/