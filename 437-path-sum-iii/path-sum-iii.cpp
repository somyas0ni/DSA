class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long,int> cnt{{0,1}};
        return dfs(root, 0, targetSum, cnt);
    }
private:
    int dfs(TreeNode* node, long sum, int target, unordered_map<long,int>& cnt) {
        if (!node) return 0;
        sum += node->val;
        int res = cnt[sum - target];
        cnt[sum]++;
        res += dfs(node->left, sum, target, cnt) + dfs(node->right, sum, target, cnt);
        cnt[sum]--;
        return res;
    }
};