class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* p1 = head;
        ListNode* p2 = prev;
        bool result = true;
        while (p2) {
            if (p1->val != p2->val) {
                result = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        curr = prev;
        prev = nullptr;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        slow->next = prev;
        return result;
    }
};