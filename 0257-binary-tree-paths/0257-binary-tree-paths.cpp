class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        string path = to_string(root->val);
        dfs(root, path, result);
        return result;
    }

    void dfs(TreeNode* node, string path, vector<string>& result) {
        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }
        if (node->left) dfs(node->left, path + "->" + to_string(node->left->val), result);
        if (node->right) dfs(node->right, path + "->" + to_string(node->right->val), result);
    }
};