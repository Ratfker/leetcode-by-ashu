class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sumMap;
        int count = 0;

        for (int a : nums1)
            for (int b : nums2)
                sumMap[a + b]++;

        for (int c : nums3)
            for (int d : nums4)
                if (sumMap.count(-(c + d)))
                    count += sumMap[-(c + d)];

        return count;
    }
};