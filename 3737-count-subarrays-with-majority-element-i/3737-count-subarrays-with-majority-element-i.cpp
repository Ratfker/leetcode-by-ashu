class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int freq = 0, total = 0;
            for (int j = i; j < n; j++) {
                total++;
                if (nums[j] == target) freq++;
                if (freq * 2 > total) count++;
            }
        }
        return count;
    }
};