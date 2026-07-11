class SummaryRanges {
public:
    map<int,int> intervals; 

    SummaryRanges() {}

    void addNum(int value) {
        if (intervals.empty()) {
            intervals[value] = value;
            return;
        }

        auto it = intervals.upper_bound(value);

        bool mergeLeft = false, mergeRight = false;

        if (it != intervals.begin()) {
            auto prev = std::prev(it);
            if (prev->second >= value) return; 
            if (prev->second + 1 == value) mergeLeft = true;
        }

        if (it != intervals.end() && it->first == value + 1) {
            mergeRight = true;
        }

        if (mergeLeft && mergeRight) {
            auto prev = std::prev(it);
            prev->second = it->second;
            intervals.erase(it);
        } else if (mergeLeft) {
            auto prev = std::prev(it);
            prev->second = value;
        } else if (mergeRight) {
            int end = it->second;
            intervals.erase(it);
            intervals[value] = end;
        } else {
            intervals[value] = value;
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto& [s, e] : intervals) res.push_back({s, e});
        return res;
    }
};
