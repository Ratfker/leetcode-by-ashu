class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        long result = -1;
        long rootVal = root->val;
        
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;
            if (node->val > rootVal) {
                if (result == -1) result = node->val;
                else result = min(result, (long)node->val);
            }
            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        return (int)result;
    }
};