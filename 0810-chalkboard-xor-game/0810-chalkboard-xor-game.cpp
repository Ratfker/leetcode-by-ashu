class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xorSum = 0;
        for (int n : nums) xorSum ^= n;
        return xorSum == 0 || nums.size() % 2 == 0;
    }
};