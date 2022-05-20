#include <iostream>
#include <numeric>
#include <algorithm>
#include <assert.h>

#include "sort.hpp"

using namespace std;

const int n = 100'000;

template <typename T>
void print(vector<T> v) {
    for_each(v.begin(), v.end(), [](T& x) { cout << x << " "; });
    cout << "\n\n";
}

int main() {
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);

    random_shuffle(v.begin(), v.end());

    auto sorter = make_shared<ShellSort<int>>();
    sorter->sort(v);

    assert(is_sorted(v.begin(), v.end()));

    if (n <= 50) {
        cout << "Sorted:\n";
        print(v);
    }

    cout << *sorter << "\n";

    system("pause");

    return 0;
}
