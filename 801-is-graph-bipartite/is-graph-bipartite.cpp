class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        for (int i = 0; i < n; i++)
            if (color[i] == 0 && !dfs(i, 1, color, graph)) return false;
        return true;
    }
private:
    bool dfs(int u, int c, vector<int>& color, vector<vector<int>>& g) {
        color[u] = c;
        for (int v : g[u]) {
            if (color[v] == c) return false;
            if (color[v] == 0 && !dfs(v, -c, color, g)) return false;
        }
        return true;
    }
};