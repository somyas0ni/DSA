class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            int sz = q.size(); double sum = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode* n = q.front(); q.pop();
                sum += n->val;
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            res.push_back(sum / sz);
        }
        return res;
    }
};