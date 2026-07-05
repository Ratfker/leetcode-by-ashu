class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        bool inComponent = false;
        while (head) {
            if (s.count(head->val)) {
                if (!inComponent) {
                    ans++;
                    inComponent = true;
                }
            } else {
                inComponent = false;
            }
            head = head->next;
        }
        return ans;
    }
};