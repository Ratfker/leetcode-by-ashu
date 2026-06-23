class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int n = s.size(), wLen = words[0].size(), wCount = words.size();
        unordered_map<string, int> freq;
        for (auto& w : words) freq[w]++;
        
        for (int i = 0; i < wLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;
            seen.reserve(wCount);
            seen.max_load_factor(0.25);
            for (int right = i; right <= n - wLen; right += wLen) {
                string_view word(s.data() + right, wLen);
                string wordStr(word);
                auto it = freq.find(wordStr);
                if (it != freq.end()) {
                    if (++seen[wordStr] > it->second) {
                        while (seen[wordStr] > it->second) {
                            string_view lw(s.data() + left, wLen);
                            string lws(lw);
                            if (--seen[lws] == 0) seen.erase(lws);
                            left += wLen;
                            count--;
                        }
                    }
                    count++;
                    if (count == wCount) result.push_back(left);
                } else {
                    seen.clear();
                    count = 0;
                    left = right + wLen;
                }
            }
        }
        return result;
    }
};