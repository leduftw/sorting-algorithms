#include <iostream>
#include <numeric>
#include <algorithm>

#include "Sort.hpp"

using namespace std;

const int n = 5;

template <typename T>
void print(vector<T> v) {
	for_each(v.begin(), v.end(), [](T x) { cout << x << " "; });
	cout << "\n\n";
}

int main() {

	vector<string> v(n);
	iota(v.begin(), v.end(), 0);

	/*
	v[0] = "Dusko";
	v[1] = "Dusko";
	v[2] = "Duska";
	v[3] = "Duskoa";
	v[4] = "Ljuban";
	*/

	cout << "Vector initialized.\n";

	random_shuffle(v.begin(), v.end());

	cout << "Shuffling done.\n";

	/*
	cout << "\nArray:\n";
	print<string>(v);
	*/

	Sort<string> *sorter = new InsertionSort<string, greater<string>>();
	sorter->sort(v);

	cout << "Vector sorted.\n\n";
	
	/*
	cout << "Sorted:\n";
	print<string>(v);
	*/

	cout << *sorter;

	delete sorter;

	return 0;
}