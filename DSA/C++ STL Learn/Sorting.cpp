#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];

void merge(int l, int r, int mid) {
	int left_size = mid - l + 1;
	int L[left_size + 1];
	int right_size = r - mid;
	int R[right_size + 1];
	for (int i = 0; i < left_size; ++i) {
		L[i] = a[i + l];
	}
	for (int i = 0; i < right_size; ++i) {
		R[i] = a[i + mid + 1];
	}
	L[left_size] = R[right_size] = INT_MAX;//if one sub array got sorted completely , then the rest will be added to the end after comparing with INT_MAX
	int l_i = 0; int r_i = 0;
	for (int i = l; i <= r; ++i) {
		if (L[l_i] <= R[r_i]) {
			a[i] = L[l_i];
			l_i++;
		} else {
			a[i] = R[r_i];
			r_i++;
		}
	}
}

void mergeSort(int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	mergeSort(l, mid);
	mergeSort(mid + 1, r);
	merge(l, r, mid);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	mergeSort(0, n - 1);

	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
}

/*
	Selection Sort
	Select the least element in unsorted sublist and put in sorted sublist
	() => (11,25,12,22,64) -> 11
	(11) => (25,12,22,64) -> 12
	...
	(11,12,22,25,64) => ()
	TC : O(n^2)

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < n; ++j) {
			if (a[j] < a[minIndex]) {
				minIndex = j;
			}
		}
		swap(a[i], a[minIndex]);
	}

	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}

	Merge Sort
	TC : O(nlog(n))
	We compare first elements of both the sub arrays and then merge them into one while sorting.
	Merging algorithm will work on sorted arrays. So we will compare first index values in both the sub arrays and put them at the end of new array and merge them and discard the merged element.
	merge step = O(n)
	divide step = O(log(n)) = equally divide the number of elements in the array(upto single element) and sort them and then merge them.
*/