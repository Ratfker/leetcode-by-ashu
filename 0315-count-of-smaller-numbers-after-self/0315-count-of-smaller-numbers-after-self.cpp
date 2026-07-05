class Solution {
    vector<int> bit;
    int size;

    void update(int i) {
        for (i++; i <= size; i += i & (-i))
            bit[i]++;
    }

    int query(int i) {
        int s = 0;
        for (i++; i > 0; i -= i & (-i))
            s += bit[i];
        return s;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int offset = 10000;
        size = 20001;
        bit.assign(size + 1, 0);
        int n = nums.size();
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            int mapped = nums[i] + offset;
            res[i] = mapped > 0 ? query(mapped - 1) : 0;
            update(mapped);
        }
        return res;
    }
};