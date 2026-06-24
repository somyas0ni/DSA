class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), count = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
            if (!vis[i]) { count++; dfs(i, isConnected, vis); }
        return count;
    }
private:
    void dfs(int u, vector<vector<int>>& m, vector<bool>& vis) {
        vis[u] = true;
        for (int v = 0; v < (int)m.size(); v++)
            if (m[u][v] && !vis[v]) dfs(v, m, vis);
    }
};