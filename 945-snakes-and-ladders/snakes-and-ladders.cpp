class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        auto cell = [&](int s) {
            int r = (s - 1) / n, c = (s - 1) % n;
            if (r % 2) c = n - 1 - c;
            return board[n - 1 - r][c];
        };
        vector<int> dist(n*n + 1, -1); dist[1] = 0;
        queue<int> q; q.push(1);
        while (!q.empty()) {
            int s = q.front(); q.pop();
            for (int k = 1; k <= 6 && s + k <= n*n; k++) {
                int nxt = s + k;
                int v = cell(nxt); if (v != -1) nxt = v;
                if (dist[nxt] == -1) { dist[nxt] = dist[s] + 1; q.push(nxt); }
            }
        }
        return dist[n*n];
    }
};