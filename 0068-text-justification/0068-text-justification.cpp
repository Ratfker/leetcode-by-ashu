class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0, n = words.size();

        while (i < n) {
            int lineLen = words[i].size();
            int j = i + 1;

            while (j < n && lineLen + 1 + words[j].size() <= maxWidth) {
                lineLen += 1 + words[j].size();
                j++;
            }

            int numWords = j - i;
            int numGaps = numWords - 1;
            string line = words[i];

            // Last line or single word: left-justified
            if (j == n || numWords == 1) {
                for (int k = i + 1; k < j; k++)
                    line += " " + words[k];
                line += string(maxWidth - line.size(), ' ');
            } else {
                int totalSpaces = maxWidth;
                for (int k = i; k < j; k++)
                    totalSpaces -= words[k].size();

                int spacePerGap = totalSpaces / numGaps;
                int extraSpaces = totalSpaces % numGaps;

                for (int k = i + 1; k < j; k++) {
                    int spaces = spacePerGap + (k - i <= extraSpaces ? 1 : 0);
                    line += string(spaces, ' ') + words[k];
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};