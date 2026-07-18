class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        int n = nums1.size(), m = nums2.size();
        if (n == 0 || m == 0 || k == 0) return result;
        
        auto cmp = [&](const pair<int,int>& a, const pair<int,int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        
        for (int i = 0; i < min(n, k); i++) {
            pq.push({i, 0});
        }
        
        while (k-- > 0 && !pq.empty()) {
            auto [i, j] = pq.top();
            pq.pop();
            result.push_back({nums1[i], nums2[j]});
            if (j + 1 < m) {
                pq.push({i, j + 1});
            }
        }
        
        return result;
    }
};