#include "knuth_gap_strategy.hpp"

vector<int> KnuthGapStrategy::get_gaps(int n) const {
    int k = (int)(log(2 * (n / 3) + 1) / log(3));
    vector<int> ans(k);

    // Ensuring valid sorting
    ans[k - 1] = 1;
    for (int i = (int)k - 2; i >= 0; i--) {
        ans[i] = 3 * ans[i + 1] + 1;
    }

    return ans;
}
