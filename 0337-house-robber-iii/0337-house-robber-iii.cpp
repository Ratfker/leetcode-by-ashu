/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        auto [withNode, withoutNode] = dfs(root);
        return max(withNode, withoutNode);
    }

private:
    pair<int,int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto [lw, lwo] = dfs(node->left);
        auto [rw, rwo] = dfs(node->right);
        int withNode = node->val + lwo + rwo;
        int withoutNode = max(lw, lwo) + max(rw, rwo);
        return {withNode, withoutNode};
    }
};