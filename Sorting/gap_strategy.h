#ifndef GAP_STRATEGY
#define GAP_STRATEGY

#include <vector>

using namespace std;

class GapStrategy { 
	
public:

	/*
		Returns gap sequence in decreasing order.
		Parameter n is size of array on which sorting is performed.
	*/
	virtual vector<int> getGaps(int n) const = 0;

	virtual ~GapStrategy() { }

};

#endif
