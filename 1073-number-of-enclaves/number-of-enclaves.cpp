class Solution {
public:
    int numEnclaves(vector<vector<int>>& g) {
        int R = g.size(), C = g[0].size();
        for (int i = 0; i < R; i++) { dfs(g,i,0); dfs(g,i,C-1); }
        for (int j = 0; j < C; j++) { dfs(g,0,j); dfs(g,R-1,j); }
        int count = 0;
        for (auto& row : g) for (int v : row) count += v;
        return count;
    }
private:
    void dfs(vector<vector<int>>& g, int i, int j) {
        if (i<0||i>=(int)g.size()||j<0||j>=(int)g[0].size()||g[i][j]!=1) return;
        g[i][j] = 0;
        dfs(g,i+1,j); dfs(g,i-1,j); dfs(g,i,j+1); dfs(g,i,j-1);
    }
};