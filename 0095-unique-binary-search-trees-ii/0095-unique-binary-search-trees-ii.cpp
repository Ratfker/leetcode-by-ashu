class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }

private:
    vector<TreeNode*> generate(int start, int end) {
        if (start > end) return {nullptr};

        vector<TreeNode*> result;
        for (int i = start; i <= end; i++) {
            auto lefts  = generate(start, i - 1);
            auto rights = generate(i + 1, end);
            for (auto l : lefts)
                for (auto r : rights) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
        }
        return result;
    }
};