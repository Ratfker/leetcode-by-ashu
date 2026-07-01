class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;
        
        // Multi-source BFS from all thieves
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        // Dijkstra-like: maximize the minimum safeness value along the path
        vector<vector<int>> safe(n, vector<int>(n, -1));
        priority_queue<tuple<int,int,int>> pq; // max-heap by safeness
        pq.push({dist[0][0], 0, 0});
        safe[0][0] = dist[0][0];
        
        while (!pq.empty()) {
            auto [d, r, c] = pq.top(); pq.pop();
            
            if (d < safe[r][c]) continue; // outdated entry
            
            if (r == n - 1 && c == n - 1) {
                return d;
            }
            
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int newSafe = min(d, dist[nr][nc]);
                    if (newSafe > safe[nr][nc]) {
                        safe[nr][nc] = newSafe;
                        pq.push({newSafe, nr, nc});
                    }
                }
            }
        }
        
        return safe[n-1][n-1];
    }
};