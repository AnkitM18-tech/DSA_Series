#include<bits/stdc++.h>
using namespace std;

// Comparator function. Controls sorting behavior
/*
bool should_i_swap(int a, int b) {
	if (a > b) return true;
	return false;
}
*/

bool should_i_swap(pair<int, int> a, pair<int, int> b) {
	// if (a > b) return true;
	// return false;
	if (a.first != b.first) {
		if (a.first > b.first) return true;
		return false;
	} else {
		if (a.second < b.second) return true;
		return false;
	}
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}
	return a.second > b.second;
}

// Decreasing order
bool cmp(int a, int b) {
	return a > b;
}

// inbuilt decreasing -> greater<pair<int,int>>() as comparator function

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	/*
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a + 2, a + n); // sort(start_addr,end+1_addr) -> a itself represents the starting index (pointer to first element)
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	*/
	// vector<int> a(n);
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		// cin >> a[i];
		cin >> a[i].first >> a[i].second;
	}
	/*
	// sort(a.begin(), a.end()); // sort(start iterator, end iterator)
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (should_i_swap(a[i], a[j])) {
				swap(a[i], a[j]);
			}
		}
	}
	*/
	sort(a.begin(), a.end(), cmp);// in built sorting comparator function says if we want to swap then we need to return false, else return false
	for (int i = 0; i < n; ++i) {
		// cout << a[i] << " ";
		cout << a[i].first << " " << a[i].second << endl;
	}
	cout << endl;
}

/*
Introsort -> hybrid sorting algorithm of 3 sorting algorithm, the best sorting algorithm
Quick sort -> if depth is not more, starts with quick sort
Insertion sort -> if number of elements are less, then it uses insertion sort
Heap sort -> if depth more then switches to heap sort

TC : O(nLog(n))

N^2 sort

for(int i=0;i<n;++i){
	for(int j=i+1;j<n;++j){
		if(a[i] > a[j]){
			swap(a[i],a[j]);
		}
	}
}
*/