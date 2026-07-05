class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        for (int i = 1; i <= n - k - 1; i++) result.push_back(i);
        int left = n - k, right = n;
        while (left <= right) {
            result.push_back(left++);
            if (left <= right) result.push_back(right--);
        }
        return result;
    }
};