class Solution {
public:
    vector<int> preorder, inorder;
    unordered_map<int, int> inMap;

    TreeNode* build(int preStart, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inMap[rootVal];
        int leftSize = mid - inStart;
        root->left  = build(preStart + 1, inStart, mid - 1);
        root->right = build(preStart + leftSize + 1, mid + 1, inEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder  = inorder;
        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;
        return build(0, 0, inorder.size() - 1);
    }
};