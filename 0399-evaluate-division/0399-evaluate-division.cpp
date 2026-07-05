class Solution {
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(const string& src, const string& dst, unordered_set<string>& visited) {
        if (graph.find(src) == graph.end()) return -1.0;
        if (src == dst) return 1.0;
        visited.insert(src);
        for (auto& [nb, val] : graph[src]) {
            if (visited.count(nb)) continue;
            double res = dfs(nb, dst, visited);
            if (res != -1.0) return val * res;
        }
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        vector<double> res;
        for (auto& q : queries) {
            if (!graph.count(q[0]) || !graph.count(q[1])) {
                res.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                res.push_back(dfs(q[0], q[1], visited));
            }
        }
        return res;
    }
};