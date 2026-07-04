class PeekingIterator : public Iterator {
    bool hasPeeked;
    int peekedVal;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        hasPeeked = false;
        peekedVal = 0;
    }

    int peek() {
        if (!hasPeeked) {
            peekedVal = Iterator::next();
            hasPeeked = true;
        }
        return peekedVal;
    }

    int next() {
        if (hasPeeked) {
            hasPeeked = false;
            return peekedVal;
        }
        return Iterator::next();
    }

    bool hasNext() const {
        return hasPeeked || Iterator::hasNext();
    }
};