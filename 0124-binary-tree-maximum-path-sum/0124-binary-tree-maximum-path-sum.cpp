class Solution {
public:
    int maxSum;

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }

    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left  = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));
        maxSum = max(maxSum, node->val + left + right);
        return node->val + max(left, right);
    }
};