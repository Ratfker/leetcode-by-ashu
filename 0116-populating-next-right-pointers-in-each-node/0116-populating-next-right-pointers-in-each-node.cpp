class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node* curr = root;
        while (curr->left) {
            Node* temp = curr;
            while (temp) {
                temp->left->next = temp->right;
                if (temp->next)
                    temp->right->next = temp->next->left;
                temp = temp->next;
            }
            curr = curr->left;
        }
        return root;
    }
};