#ifndef PIVOT_STRATEGY
#define PIVOT_STRATEGY

#include <vector>

using namespace std;

template <typename T>
class PivotStrategy {

public:

	virtual T getPivot(vector<T> &arr, int lo, int hi) const = 0;

};

#endif
