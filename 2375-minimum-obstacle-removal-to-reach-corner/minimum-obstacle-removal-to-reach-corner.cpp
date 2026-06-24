class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<vector<int>> dist(R, vector<int>(C, INT_MAX));
        deque<pair<int,int>> dq; dq.push_front({0, 0}); dist[0][0] = 0;
        int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
        while (!dq.empty()) {
            auto [x, y] = dq.front(); dq.pop_front();
            for (int d = 0; d < 4; d++) {
                int nx=x+dx[d], ny=y+dy[d];
                if (nx>=0&&nx<R&&ny>=0&&ny<C) {
                    int nd = dist[x][y] + grid[nx][ny];
                    if (nd < dist[nx][ny]) {
                        dist[nx][ny] = nd;
                        if (grid[nx][ny]) dq.push_back({nx, ny});
                        else dq.push_front({nx, ny});
                    }
                }
            }
        }
        return dist[R-1][C-1];
    }
};