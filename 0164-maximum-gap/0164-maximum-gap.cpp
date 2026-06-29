class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        if (minVal == maxVal) return 0;

        int bucketSize  = max(1, (maxVal - minVal) / (n - 1));
        int bucketCount = (maxVal - minVal) / bucketSize + 1;

        vector<int> bMin(bucketCount, INT_MAX);
        vector<int> bMax(bucketCount, INT_MIN);

        for (int num : nums) {
            int idx = (num - minVal) / bucketSize;
            bMin[idx] = min(bMin[idx], num);
            bMax[idx] = max(bMax[idx], num);
        }

        int maxGap = 0, prevMax = minVal;

        for (int i = 0; i < bucketCount; i++) {
            if (bMin[i] == INT_MAX) continue;
            maxGap = max(maxGap, bMin[i] - prevMax);
            prevMax = bMax[i];
        }

        return maxGap;
    }
};