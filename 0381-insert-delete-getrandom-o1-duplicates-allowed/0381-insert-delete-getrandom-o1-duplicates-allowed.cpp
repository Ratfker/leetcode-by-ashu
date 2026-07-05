class RandomizedCollection {
    unordered_map<int, unordered_set<int>> mp;
    vector<int> arr;

public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool notPresent = mp[val].empty();
        arr.push_back(val);
        mp[val].insert(arr.size() - 1);
        return notPresent;
    }

    bool remove(int val) {
        if (mp[val].empty()) return false;
        int removeIdx = *mp[val].begin();
        mp[val].erase(removeIdx);
        int last = arr.back();
        if (removeIdx != (int)arr.size() - 1) {
            arr[removeIdx] = last;
            mp[last].erase(arr.size() - 1);
            mp[last].insert(removeIdx);
        }
        arr.pop_back();
        return true;
    }

    int getRandom() {
        return arr[rand() % arr.size()];
    }
};