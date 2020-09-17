#include <iostream>
#include <numeric>
#include <algorithm>

#include "sort.h"

using namespace std;

const int n = 10000;

template <typename T>
void print(vector<T> v) {
	for_each(v.begin(), v.end(), [](T &x) { cout << x << " "; });
	cout << "\n\n";
}

int main() {
	vector<int> v(n);
	iota(v.begin(), v.end(), 0);

	cout << "Vector initialized.\n";

	random_shuffle(v.begin(), v.end());

	cout << "Shuffling done.\n";

	Sort<int> *sorter = new InsertionSort<int>();
	sorter->sort(v);

	cout << "Vector sorted.\n\n";
	
	//cout << "Sorted:\n";
	//print<int>(v);

	cout << *sorter;

	delete sorter;

	return 0;
}
