class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> arr(n);
        for (int i = 0; i < n; i++) arr[i] = {nums[i], i};
        sort(arr.begin(), arr.end());

        vector<int> pos(n), val(n);
        for (int i = 0; i < n; i++) {
            val[i] = arr[i].first;
            pos[arr[i].second] = i;
        }

        vector<int> R(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (r < i) r = i;
            while (r + 1 < n && val[r+1] - val[i] <= maxDiff) r++;
            R[i] = r;
        }

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        for (int i = 0; i + 1 < n; i++) {
            if (val[i+1] - val[i] <= maxDiff) {
                int a = find(i), b = find(i+1);
                if (a != b) parent[a] = b;
            }
        }

        const int LOG = 18;
        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = R;
        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++)
                up[k][i] = up[k-1][up[k-1][i]];

        auto queryDist = [&](int pu, int pv) -> int {
            if (pu == pv) return 0;
            if (pu > pv) swap(pu, pv);
            if (find(pu) != find(pv)) return -1;
            if (R[pu] >= pv) return 1;
            int cur = pu, steps = 0;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < pv) {
                    steps += (1 << k);
                    cur = up[k][cur];
                }
            }
            return steps + 1;
        };

        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int u = queries[i][0], v = queries[i][1];
            ans[i] = queryDist(pos[u], pos[v]);
        }
        return ans;
    }
};