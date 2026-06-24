class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            int sz = q.size(); vector<int> level;
            for (int i = 0; i < sz; i++) {
                TreeNode* n = q.front(); q.pop();
                level.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};