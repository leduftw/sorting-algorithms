#include "knuth_gap_strategy.h"


vector<size_t> KnuthGapStrategy::getGaps(size_t n) const {
	size_t k = log(2 * (n / 3) + 1) / log(3);
	vector<size_t> ans(k);

	ans[k - 1] = 1;  // ensuring valid sorting
	for (int i = (int)k - 2; i >= 0; i--) {
		ans[i] = 3 * ans[i + 1] + 1;
	}

	return ans;
}
