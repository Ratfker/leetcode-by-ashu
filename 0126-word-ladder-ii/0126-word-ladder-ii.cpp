class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        if (!wordSet.count(endWord)) return result;

        unordered_map<string, vector<string>> parents;
        unordered_map<string, int> distance;
        queue<string> q;

        q.push(beginWord);
        distance[beginWord] = 0;

        bool found = false;
        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> visited;
            while (size--) {
                string word = q.front(); q.pop();
                string curr = word;
                for (int i = 0; i < curr.size(); i++) {
                    char orig = curr[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        curr[i] = c;
                        if (!wordSet.count(curr)) continue;
                        if (distance.count(curr) && distance[curr] < distance[word] + 1) continue;
                        if (!distance.count(curr)) {
                            distance[curr] = distance[word] + 1;
                            q.push(curr);
                            visited.insert(curr);
                        }
                        parents[curr].push_back(word);
                        if (curr == endWord) found = true;
                    }
                    curr[i] = orig;
                }
            }
            for (auto& w : visited) wordSet.erase(w);
        }

        if (!found) return result;

        vector<string> path = {endWord};
        backtrack(endWord, beginWord, parents, path, result);
        return result;
    }

    void backtrack(string word, string& beginWord, unordered_map<string, vector<string>>& parents,
                   vector<string>& path, vector<vector<string>>& result) {
        if (word == beginWord) {
            result.push_back(vector<string>(path.rbegin(), path.rend()));
            return;
        }
        for (auto& parent : parents[word]) {
            path.push_back(parent);
            backtrack(parent, beginWord, parents, path, result);
            path.pop_back();
        }
    }
};