#include "knuth_gap_strategy.h"

vector<int> KnuthGapStrategy::getGaps(int n) const {
	int k = (int) (log(2 * (n / 3) + 1) / log(3));
	vector<int> ans(k);

	ans[k - 1] = 1;  // ensuring valid sorting
	for (int i = (int)k - 2; i >= 0; i--) {
		ans[i] = 3 * ans[i + 1] + 1;
	}

	return ans;
}
