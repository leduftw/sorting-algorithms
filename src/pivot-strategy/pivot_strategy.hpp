#ifndef PIVOT_STRATEGY
#define PIVOT_STRATEGY

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class PivotStrategy {

public:

    virtual T get_pivot(vector<T>& arr, int lo, int hi) const = 0;

    virtual ~PivotStrategy() { }

};

#endif
