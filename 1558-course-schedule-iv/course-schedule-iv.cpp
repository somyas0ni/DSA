class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereq,
                                     vector<vector<int>>& queries) {
        vector<vector<bool>> reach(n, vector<bool>(n, false));
        for (auto& p : prereq) reach[p[0]][p[1]] = true;
        for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
            if (reach[i][k] && reach[k][j]) reach[i][j] = true;
        vector<bool> res;
        for (auto& q : queries) res.push_back(reach[q[0]][q[1]]);
        return res;
    }
};