class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        
        vector<unordered_set<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) leaves.push_back(i);
        }
        
        int remaining = n;
        while (remaining > 2) {
            remaining -= leaves.size();
            vector<int> newLeaves;
            for (int leaf : leaves) {
                int neighbor = *adj[leaf].begin();
                adj[neighbor].erase(leaf);
                if (adj[neighbor].size() == 1) {
                    newLeaves.push_back(neighbor);
                }
            }
            leaves = newLeaves;
        }
        
        return leaves;
    }
};