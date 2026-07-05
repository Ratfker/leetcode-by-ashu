class Solution {
    vector<int> original;
    vector<int> arr;

public:
    Solution(vector<int>& nums) {
        original = nums;
        arr = nums;
    }

    vector<int> reset() {
        arr = original;
        return arr;
    }

    vector<int> shuffle() {
        int n = arr.size();
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(arr[i], arr[j]);
        }
        return arr;
    }
};