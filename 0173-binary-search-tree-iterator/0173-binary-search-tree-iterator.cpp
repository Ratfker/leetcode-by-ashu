class BSTIterator {
private:
    stack<TreeNode*> stk;
    
    void pushLeft(TreeNode* node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        pushLeft(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};