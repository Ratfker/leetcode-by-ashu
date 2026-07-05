class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;
        int i = 0;
        int n = preorder.size();
        
        while (i < n) {
            if (slots <= 0) return false;
            
            if (preorder[i] == ',') {
                i++;
                continue;
            }
            
            if (preorder[i] == '#') {
                slots--;
                i++;
            } else {
                while (i < n && preorder[i] != ',') i++;
                slots--;
                slots += 2;
            }
        }
        
        return slots == 0;
    }
};