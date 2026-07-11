class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        vector<int> res;
        for (int n : nums2) {
            if (set1.count(n)) {
                res.push_back(n);
                set1.erase(n);
            }
        }
        return res;
    }
};