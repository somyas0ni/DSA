class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* n = q.front(); q.pop();
                if (i == sz - 1) res.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
        }
        return res;
    }
};