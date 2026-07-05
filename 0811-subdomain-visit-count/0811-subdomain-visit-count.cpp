class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> cnt;
        for (const string& cp : cpdomains) {
            int space = cp.find(' ');
            int count = stoi(cp.substr(0, space));
            string domain = cp.substr(space + 1);
            cnt[domain] += count;
            for (int i = 0; i < domain.size(); i++) {
                if (domain[i] == '.') {
                    cnt[domain.substr(i + 1)] += count;
                }
            }
        }
        vector<string> ans;
        for (auto& [dom, c] : cnt)
            ans.push_back(to_string(c) + " " + dom);
        return ans;
    }
};