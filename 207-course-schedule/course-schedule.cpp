class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n); vector<int> indeg(n, 0);
        for (auto& p : prerequisites) { adj[p[1]].push_back(p[0]); indeg[p[0]]++; }
        queue<int> q;
        for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
        int done = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop(); done++;
            for (int v : adj[u]) if (--indeg[v] == 0) q.push(v);
        }
        return done == n;
    }
};