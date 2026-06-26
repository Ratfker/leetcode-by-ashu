class Solution {
public:
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }

private:
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (prev && prev->val > node->val) {
            if (!first) first = prev;
            second = node;
        }
        prev = node;
        inorder(node->right);
    }
};