class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(candidates, target, 0, curr, res);
        return res;
    }

    void backtrack(vector<int>& c, int rem, int start, vector<int>& curr, vector<vector<int>>& res) {
        if (rem == 0) { res.push_back(curr); return; }
        for (int i = start; i < c.size(); i++) {
            if (c[i] > rem) break;
            if (i > start && c[i] == c[i-1]) continue;
            curr.push_back(c[i]);
            backtrack(c, rem - c[i], i + 1, curr, res);
            curr.pop_back();
        }
    }
};
