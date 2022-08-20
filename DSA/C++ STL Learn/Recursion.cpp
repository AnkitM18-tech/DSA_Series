#include<bits/stdc++.h>
using namespace std;

int fact(int n) {
	if (n == 0) return 1;
	return n * fact(n - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << fact(n);
}

//Without Base condition, our code will run indefinitely and it will give segmentation fault
// The statements written before the recursive function are executed while moving forward (jaate time compute hoti hai). Aur jo function ke baad statements hai woh return karte time compute hoti hain.
// TC : Number of function calls and complexity of each function => n * O(1) = O(n)