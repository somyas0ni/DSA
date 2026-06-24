class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res; vector<int> path;
        vector<bool> used(nums.size(), false);
        dfs(nums, used, path, res);
        return res;
    }
private:
    void dfs(vector<int>& a, vector<bool>& used, vector<int>& path, vector<vector<int>>& res) {
        if (path.size() == a.size()) { res.push_back(path); return; }
        for (int i = 0; i < (int)a.size(); i++) {
            if (used[i]) continue;
            used[i] = true; path.push_back(a[i]);
            dfs(a, used, path, res);
            path.pop_back(); used[i] = false;
        }
    }
};