class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        multiset<int> lo, hi;

        auto rebalance = [&]() {
            if (lo.size() > hi.size() + 1) {
                hi.insert(*lo.rbegin());
                lo.erase(prev(lo.end()));
            } else if (hi.size() > lo.size()) {
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }
        };

        for (int i = 0; i < (int)nums.size(); i++) {
            if (lo.empty() || nums[i] <= *lo.rbegin())
                lo.insert(nums[i]);
            else
                hi.insert(nums[i]);

            rebalance();

            if (i >= k) {
                int out = nums[i - k];
                if (lo.count(out))
                    lo.erase(lo.find(out));
                else
                    hi.erase(hi.find(out));
                rebalance();
            }

            if (i >= k - 1) {
                if (k % 2 == 1)
                    result.push_back(*lo.rbegin());
                else
                    result.push_back(((double)*lo.rbegin() + *hi.begin()) / 2.0);
            }
        }

        return result;
    }
};