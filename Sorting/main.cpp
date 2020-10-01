#include <iostream>
#include <numeric>
#include <algorithm>
#include <assert.h>

#include "sort.hpp"

using namespace std;

const int n = 1'000;

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

	return 0;
}
