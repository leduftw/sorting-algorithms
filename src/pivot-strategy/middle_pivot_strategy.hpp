#ifndef MIDDLE_PIVOT_STRATEGY
#define MIDDLE_PIVOT_STRATEGY

#include <iostream>

#include "pivot_strategy.hpp"

using namespace std;

template <typename T>
class MiddlePivotStrategy : public PivotStrategy<T> {

public:

    /*
        Selects middle element from partition as pivot.
    */
    virtual T get_pivot(vector<T>& arr, int lo, int hi) const override {
        return arr[lo + (hi - lo) / 2];
    }

    virtual ~MiddlePivotStrategy() { }

};

#endif
