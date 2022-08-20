#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		s.insert(x);
	}
	// auto it = lower_bound(s.begin(), s.end(), 5); // in case of sets, maps if we use lower_bound and upper_bound like this, then it is a O(n) function, and sometimes it will give TLE. instead we can use them like
	auto it = s.lower_bound(5); // log(n) ops
	cout << (*it) << endl;
	// In case of maps, LB and UB is implemented on keys
	/*
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	// int *ptr = lower_bound(a, a + n, 26);
	int *ptr = upper_bound(a, a + n, 25);
	// auto it = ---(a.begin(),a.end(),x)
	if (ptr == (a + n)) { // a+n -> non existing // it == a.end()
		cout << "Not Found";
	} else {
		cout << *ptr << endl; // *it
	}
	*/
}

/*
for the lower_bound and upper_bound to work in log(n) time, the array or container must be sorted. If they are not sorted then it will work in O(n) time.

lower_bound(a,a+n,x) -> if the value is present then return that value's iterator/pointer, if not present then return the value just greater than the value. if there is no element greater than that value then it will return a pointer to the end+1(a+n) address in case of arrays, in case of vectors will return v.end() (non-existent) -> value not less than the desired value

if multiple values present then the first value's iterator will be returned.

can be used in case of pairs and strings

upper_bound(a,a+n,x) -> return the iterator to the value greater than the value

they both return location of the element. => in case of arrays return pointer and in case of vectors return iterator

If sorted arrays and vectors then TC: O(log(n))
*/