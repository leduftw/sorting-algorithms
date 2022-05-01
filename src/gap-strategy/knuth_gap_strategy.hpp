#ifndef KNUTH_GAP_STRATEGY
#define KNUTH_GAP_STRATEGY

#include <iostream>
#include <vector>

#include "gap_strategy.hpp"

using namespace std;

class KnuthGapStrategy : public GapStrategy { 

public:

	/*
		Gaps are of the form (3^k - 1) / 2, where k = 1, 2, 3,...
		This can be expressed recursively: A(k) = 3*A(k-1) + 1.
		Largest gap should not be greater than ceil(n / 3).

		This means that largest valid gap is obtained when
		k = floor(log3(2 * ceil(n / 3) + 1)), which is also
		the size of returned result array.
	*/
	virtual vector<int> getGaps(int n) const override;

	virtual ~KnuthGapStrategy() { 
		//cout << "KGS destructor called!\n";
	}

};

#endif
