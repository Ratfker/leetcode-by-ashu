class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0, n = data.size();
        while (i < n) {
            int b = data[i] & 0xFF;
            int bytes;
            if      ((b >> 7) == 0b0)     bytes = 1;
            else if ((b >> 5) == 0b110)   bytes = 2;
            else if ((b >> 4) == 0b1110)  bytes = 3;
            else if ((b >> 3) == 0b11110) bytes = 4;
            else return false;
            for (int j = 1; j < bytes; j++) {
                if (i + j >= n) return false;
                if ((data[i + j] & 0xC0) != 0x80) return false;
            }
            i += bytes;
        }
        return true;
    }
};