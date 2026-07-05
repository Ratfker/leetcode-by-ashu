class NumArray {
    vector<int> bit;
    vector<int> nums;
    int n;

    void update_(int i, int delta) {
        for (i++; i <= n; i += i & (-i))
            bit[i] += delta;
    }

    int query(int i) {
        int s = 0;
        for (i++; i > 0; i -= i & (-i))
            s += bit[i];
        return s;
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            update_(i, nums[i]);
    }

    void update(int index, int val) {
        update_(index, val - nums[index]);
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        return query(right) - (left > 0 ? query(left - 1) : 0);
    }
};