class MapSum {
    unordered_map<string,int> mp;
    unordered_map<string,int> prefixSum;
public:
    MapSum() {}
    
    void insert(string key, int val) {
        int delta = val - mp[key];
        mp[key] = val;
        string prefix = "";
        for (char c : key) {
            prefix += c;
            prefixSum[prefix] += delta;
        }
    }
    
    int sum(string prefix) {
        return prefixSum.count(prefix) ? prefixSum[prefix] : 0;
    }
};