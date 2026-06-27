class Solution {
public:
    unordered_map<int, int> inMap;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postEnd) {
        if (inStart > inEnd) return nullptr;
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inMap[rootVal];
        int leftSize = mid - inStart;
        root->left  = build(inorder, postorder, inStart, mid - 1, postEnd - (inEnd - mid) - 1);
        root->right = build(inorder, postorder, mid + 1, inEnd, postEnd - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;
        return build(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
    }
};