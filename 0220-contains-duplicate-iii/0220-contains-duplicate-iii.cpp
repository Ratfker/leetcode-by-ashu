class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        map<long, long> window;
        for (int i = 0; i < (int)nums.size(); i++) {
            long num = nums[i];
            auto it = window.lower_bound(num - valueDiff);
            if (it != window.end() && it->first <= num + valueDiff)
                return true;
            window[num] = i;
            if (i >= indexDiff)
                window.erase(nums[i - indexDiff]);
        }
        return false;
    }
};