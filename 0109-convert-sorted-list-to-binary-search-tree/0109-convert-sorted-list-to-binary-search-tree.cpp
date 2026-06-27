class Solution {
public:
    ListNode* mid;

    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);
        ListNode* mid = findMid(head);
        TreeNode* root = new TreeNode(mid->val);
        root->right = sortedListToBST(mid->next);
        mid->next = nullptr;
        root->left = sortedListToBST(head);
        return root;
    }

    ListNode* findMid(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev) prev->next = nullptr;
        return slow;
    }
};