class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int patches = 0;
        int i = 0;
        int len = nums.size();
        
        while (miss <= n) {
            if (i < len && nums[i] <= miss) {
                miss += nums[i];
                i++;
            } else {
                miss += miss;
                patches++;
            }
        }
        
        return patches;
    }
};