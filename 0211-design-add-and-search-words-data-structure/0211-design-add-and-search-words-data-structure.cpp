class WordDictionary {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
            isEnd = false;
        }
    };

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }

        node->isEnd = true;
    }

    bool dfs(string& word, int index, TrieNode* node) {
        if (!node)
            return false;

        if (index == word.size())
            return node->isEnd;

        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (dfs(word, index + 1, node->children[i]))
                    return true;
            }
            return false;
        }

        return dfs(word, index + 1, node->children[word[index] - 'a']);
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};