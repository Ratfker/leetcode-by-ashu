class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (int n : nums) arr.push_back(to_string(n));
        sort(arr.begin(), arr.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        if (arr[0] == "0") return "0";
        string result;
        for (string& s : arr) result += s;
        return result;
    }
};