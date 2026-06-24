class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int best = 0;
        for (int i = 0; i < (int)grid.size(); i++)
            for (int j = 0; j < (int)grid[0].size(); j++)
                if (grid[i][j] == 1) best = max(best, dfs(grid, i, j));
        return best;
    }
private:
    int dfs(vector<vector<int>>& g, int i, int j) {
        if (i<0||i>=(int)g.size()||j<0||j>=(int)g[0].size()||g[i][j]!=1) return 0;
        g[i][j] = 0;
        return 1 + dfs(g,i+1,j) + dfs(g,i-1,j) + dfs(g,i,j+1) + dfs(g,i,j-1);
    }
};