class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        for (auto& t : tickets) {
            graph[t[0]].insert(t[1]);
        }
        vector<string> result;
        stack<string> st;
        st.push("JFK");
        while (!st.empty()) {
            string airport = st.top();
            if (graph[airport].empty()) {
                result.push_back(airport);
                st.pop();
            } else {
                string next = *graph[airport].begin();
                graph[airport].erase(graph[airport].begin());
                st.push(next);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};