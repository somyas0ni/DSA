class Solution {
    int prev = -1, best = INT_MAX;
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return best;
    }
private:
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (prev != -1) best = min(best, node->val - prev);
        prev = node->val;
        inorder(node->right);
    }
};