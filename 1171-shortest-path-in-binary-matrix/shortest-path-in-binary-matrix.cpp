class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n-1][n-1]) return -1;
        queue<pair<int,int>> q; q.push({0,0}); grid[0][0] = 1;
        int len = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                auto [x, y] = q.front(); q.pop();
                if (x == n-1 && y == n-1) return len;
                for (int dx = -1; dx <= 1; dx++) for (int dy = -1; dy <= 1; dy++) {
                    int nx = x+dx, ny = y+dy;
                    if (nx>=0&&nx<n&&ny>=0&&ny<n&&grid[nx][ny]==0) {
                        grid[nx][ny] = 1; q.push({nx, ny});
                    }
                }
            }
            len++;
        }
        return -1;
    }
};