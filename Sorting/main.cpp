#include <iostream>
#include <numeric>
#include <algorithm>
#include <assert.h>

#include "sort.hpp"

using namespace std;

const int n = 1'000'000;

template <typename T>
void print(vector<T> v) {
	for_each(v.begin(), v.end(), [](T &x) { cout << x << " "; });
	cout << "\n\n";
}

int main() {
	/*
	vector<int> v(n);
	iota(v.begin(), v.end(), 0);

	cout << "Vector initialized.\n";

	random_shuffle(v.begin(), v.end());

	cout << "Shuffling done.\n";

	shared_ptr<ShellSort<int, greater<int>>> sorter = make_shared<ShellSort<int, greater<int>>>();
	sorter->sort(v);

	cout << "Vector sorted.\n\n";
	
	assert(is_sorted(v.begin(), v.end(), greater<int>()));

	cout << "Changing strategy...\n\n";

	sorter->setGapStrategy(make_shared<KnuthGapStrategy>());

	random_shuffle(v.begin(), v.end());

	cout << "Shuffling done.\n";

	sorter->sort(v);

	cout << "Vector sorted.\n\n";

	assert(is_sorted(v.begin(), v.end(), greater<int>()));

	//cout << "Sorted:\n";
	//print<int>(v);

	cout << *sorter;
	*/

	vector<int> v(n);
	iota(v.begin(), v.end(), 1);

	random_shuffle(v.begin(), v.end());

	/*
	cout << "After shuffling:\n";
	print(v);

	make_heap(v.begin(), v.end(), greater<int>());
	cout << "Heap created:\n";
	print(v);

	pop_heap(v.begin(), v.end());
	cout << "First element popped!\n";
	print(v);
	*/

	auto sorter = make_shared<STLHeapSort<int>>();
	sorter->sort(v);

	assert(is_sorted(v.begin(), v.end()));

	cout << "Sorted:\n";
	//print(v);

	cout << *sorter << "\n";

	return 0;
}
