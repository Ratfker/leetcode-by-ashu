class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> best;
        
        for (int i = max(0, k - n); i <= min(k, m); i++) {
            vector<int> candidate = merge(maxSubsequence(nums1, i), maxSubsequence(nums2, k - i));
            if (greater(candidate, 0, best, 0)) {
                best = candidate;
            }
        }
        
        return best;
    }
    
private:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> stack;
        int n = nums.size();
        int drop = n - k;
        
        for (int num : nums) {
            while (drop > 0 && !stack.empty() && stack.back() < num) {
                stack.pop_back();
                drop--;
            }
            stack.push_back(num);
        }
        
        stack.resize(k);
        return stack;
    }
    
    vector<int> merge(vector<int> a, vector<int> b) {
        vector<int> result;
        int i = 0, j = 0;
        
        while (i < a.size() || j < b.size()) {
            if (greater(a, i, b, j)) {
                result.push_back(a[i++]);
            } else {
                result.push_back(b[j++]);
            }
        }
        
        return result;
    }
    
    bool greater(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < a.size() && j < b.size()) {
            if (a[i] != b[j]) return a[i] > b[j];
            i++;
            j++;
        }
        return i < a.size();
    }
};