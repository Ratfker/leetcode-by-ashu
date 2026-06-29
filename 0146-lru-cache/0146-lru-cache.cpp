class LRUCache {
    int cap;
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> mp;

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (!mp.count(key)) return -1;
        cache.splice(cache.begin(), cache, mp[key]);
        return mp[key]->second;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            cache.splice(cache.begin(), cache, mp[key]);
            mp[key]->second = value;
        } else {
            if (cache.size() == cap) {
                mp.erase(cache.back().first);
                cache.pop_back();
            }
            cache.push_front({key, value});
            mp[key] = cache.begin();
        }
    }
};