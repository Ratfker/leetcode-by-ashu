class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return result;
    }

    void dfs(TreeNode* node, int remaining) {
        if (!node) return;
        path.push_back(node->val);
        if (!node->left && !node->right && remaining == node->val)
            result.push_back(path);
        dfs(node->left, remaining - node->val);
        dfs(node->right, remaining - node->val);
        path.pop_back();
    }
};