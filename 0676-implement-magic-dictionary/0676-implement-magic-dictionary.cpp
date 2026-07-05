class MagicDictionary {
    vector<string> words;
public:
    MagicDictionary() {}
    
    void buildDict(vector<string> dictionary) {
        words = dictionary;
    }
    
    bool search(string searchWord) {
        for (string& word : words) {
            if (word.size() != searchWord.size()) continue;
            int diff = 0;
            for (int i = 0; i < word.size(); i++) {
                if (word[i] != searchWord[i]) diff++;
            }
            if (diff == 1) return true;
        }
        return false;
    }
};