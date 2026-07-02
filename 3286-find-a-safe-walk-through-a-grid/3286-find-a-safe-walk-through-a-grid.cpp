class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> maxHealth(m, vector<int>(n, -1));
        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;
        maxHealth[0][0] = startHealth;
        queue<pair<int,int>> q;
        q.push({0, 0});
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int nh = maxHealth[x][y] - grid[nx][ny];
                if (nh <= 0) continue;
                if (nh > maxHealth[nx][ny]) {
                    maxHealth[nx][ny] = nh;
                    q.push({nx, ny});
                }
            }
        }
        return maxHealth[m-1][n-1] >= 1;
    }
};