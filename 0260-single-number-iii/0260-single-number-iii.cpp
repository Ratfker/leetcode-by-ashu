class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorAll = 0;
        for (int n : nums) xorAll ^= n;
        
        long diff = xorAll & (-xorAll);
        
        int a = 0;
        for (int n : nums)
            if (n & diff) a ^= n;
        
        return {a, (int)(xorAll ^ a)};
    }
};