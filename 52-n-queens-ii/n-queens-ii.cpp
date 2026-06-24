class Solution {
    int n, count = 0;
    vector<bool> col, d1, d2;
public:
    int totalNQueens(int N) {
        n = N; col.assign(n,false); d1.assign(2*n,false); d2.assign(2*n,false);
        dfs(0);
        return count;
    }
private:
    void dfs(int r) {
        if (r == n) { count++; return; }
        for (int c = 0; c < n; c++) {
            if (col[c] || d1[r-c+n] || d2[r+c]) continue;
            col[c] = d1[r-c+n] = d2[r+c] = true;
            dfs(r + 1);
            col[c] = d1[r-c+n] = d2[r+c] = false;
        }
    }
};