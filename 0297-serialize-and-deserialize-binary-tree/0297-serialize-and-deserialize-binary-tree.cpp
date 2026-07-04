class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return build(ss);
    }

private:
    TreeNode* build(istringstream& ss) {
        string token;
        getline(ss, token, ',');
        if (token == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(token));
        node->left = build(ss);
        node->right = build(ss);
        return node;
    }
};