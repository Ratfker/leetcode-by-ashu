class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pref(n + 1);
        pref[0] = 0;
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        
        vector<int> sorted_pref = pref;
        sort(sorted_pref.begin(), sorted_pref.end());
        sorted_pref.erase(unique(sorted_pref.begin(), sorted_pref.end()), sorted_pref.end());
        
        auto compress = [&](int v) {
            return lower_bound(sorted_pref.begin(), sorted_pref.end(), v) - sorted_pref.begin() + 1;
        };
        
        int m = sorted_pref.size();
        vector<int> bit(m + 2, 0);
        
        auto update = [&](int i) {
            for (; i <= m; i += i & (-i)) bit[i]++;
        };
        auto query = [&](int i) {
            int s = 0;
            for (; i > 0; i -= i & (-i)) s += bit[i];
            return s;
        };
        
        long long ans = 0;
        for (int k = 0; k <= n; k++) {
            int cur = compress(pref[k]);
            ans += query(cur - 1);
            update(cur);
        }
        return ans;
    }
};