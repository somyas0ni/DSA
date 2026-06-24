class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> best(n, vector<int>(n, INT_MAX));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0}); best[0][0] = grid[0][0];
        int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
        while (!pq.empty()) {
            auto [t, x, y] = pq.top(); pq.pop();
            if (x == n-1 && y == n-1) return t;
            for (int d = 0; d < 4; d++) {
                int nx=x+dx[d], ny=y+dy[d];
                if (nx>=0&&nx<n&&ny>=0&&ny<n) {
                    int nt = max(t, grid[nx][ny]);
                    if (nt < best[nx][ny]) { best[nx][ny] = nt; pq.push({nt, nx, ny}); }
                }
            }
        }
        return 0;
    }
};