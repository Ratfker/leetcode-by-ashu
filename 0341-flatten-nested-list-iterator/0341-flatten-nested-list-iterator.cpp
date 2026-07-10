/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<pair<vector<NestedInteger>*, int>> stk;

    NestedIterator(vector<NestedInteger> &nestedList) {
        stk.push({&nestedList, 0});
    }

    int next() {
        hasNext();
        auto& [list, idx] = stk.top();
        int val = (*list)[idx].getInteger();
        idx++;
        return val;
    }

    bool hasNext() {
        while (!stk.empty()) {
            auto& [list, idx] = stk.top();
            if (idx == (int)list->size()) {
                stk.pop();
                continue;
            }
            if ((*list)[idx].isInteger()) return true;
            vector<NestedInteger>* nested = const_cast<vector<NestedInteger>*>(&(*list)[idx].getList());
            idx++;
            stk.push({nested, 0});
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */