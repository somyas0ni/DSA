class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q; q.push(root); bool ltr = true;
        while (!q.empty()) {
            int sz = q.size(); vector<int> level(sz);
            for (int i = 0; i < sz; i++) {
                TreeNode* n = q.front(); q.pop();
                int idx = ltr ? i : sz - 1 - i;
                level[idx] = n->val;
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            res.push_back(level); ltr = !ltr;
        }
        return res;
    }
};