class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        vector<vector<int>> trees;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (forest[i][j] > 1)
                    trees.push_back({forest[i][j], i, j});
        sort(trees.begin(), trees.end());
        
        int sx = 0, sy = 0, total = 0;
        for (auto& t : trees) {
            int tx = t[1], ty = t[2];
            int dist = bfs(forest, sx, sy, tx, ty);
            if (dist == -1) return -1;
            total += dist;
            sx = tx; sy = ty;
        }
        return total;
    }
    
    int bfs(vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) return 0;
        int m = forest.size(), n = forest[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({sx, sy});
        visited[sx][sy] = true;
        int steps = 0;
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!q.empty()) {
            steps++;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [x, y] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && forest[nx][ny] != 0) {
                        if (nx == tx && ny == ty) return steps;
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};