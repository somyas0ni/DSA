class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size(), C = grid[0].size(), count = 0;
        for (int i = 0; i < R; i++) for (int j = 0; j < C; j++)
            if (grid[i][j] == '1') { count++; dfs(grid, i, j); }
        return count;
    }
private:
    void dfs(vector<vector<char>>& g, int i, int j) {
        if (i<0||i>=(int)g.size()||j<0||j>=(int)g[0].size()||g[i][j]!='1') return;
        g[i][j] = '0';
        dfs(g,i+1,j); dfs(g,i-1,j); dfs(g,i,j+1); dfs(g,i,j-1);
    }
};