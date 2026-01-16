class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLen = 0;

            // Pack as many words as possible
            while (j < n && lineLen + words[j].length() + (j - i) <= maxWidth) {
                lineLen += words[j].length();
                j++;
            }

            int gaps = j - i - 1;
            string line;

            // Case 1: Last line OR single word
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                // Pad remaining spaces
                line += string(maxWidth - line.length(), ' ');
            }
            // Case 2: Fully justified
            else {
                int totalSpaces = maxWidth - lineLen;
                int spaceEach = totalSpaces / gaps;
                int extra = totalSpaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += string(spaceEach + (extra > 0 ? 1 : 0), ' ');
                        if (extra > 0) extra--;
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};
