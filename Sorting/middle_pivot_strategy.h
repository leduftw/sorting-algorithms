#ifndef MIDDLE_PIVOT_STRATEGY
#define MIDDLE_PIVOT_STRATEGY

#include "pivot_strategy.h"

template <typename T>
class MiddlePivotStrategy : public PivotStrategy<T> {

public:

	/*
		Selects middle element from partition as pivot.
	*/
	virtual T getPivot(vector<T> &arr, int lo, int hi) const override {
		return arr[lo + (hi - lo) / 2];
	}

};

#endif
