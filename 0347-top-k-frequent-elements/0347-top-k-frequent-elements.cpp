class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int n : nums) freq[n]++;

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, cnt] : freq) buckets[cnt].push_back(num);

        vector<int> res;
        for (int i = buckets.size() - 1; i >= 0 && (int)res.size() < k; i--) {
            for (int num : buckets[i]) {
                res.push_back(num);
                if ((int)res.size() == k) break;
            }
        }
        return res;
    }
};