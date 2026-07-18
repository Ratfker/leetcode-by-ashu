/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* head;
    
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int result = head->val;
        ListNode* node = head->next;
        int count = 2;
        
        while (node != nullptr) {
            if (rand() % count == 0) {
                result = node->val;
            }
            node = node->next;
            count++;
        }
        
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */