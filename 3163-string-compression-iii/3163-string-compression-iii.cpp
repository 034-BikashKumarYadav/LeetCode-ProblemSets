class Solution {
public:
    string compressedString(string word) {
         std::string comp = "";
        int n = word.length();
        for (int i = 0; i < n; ) {
            char currentChar = word[i];
            int count = 0;
            while (i < n && word[i] == currentChar && count < 9) {
                count++;
                i++;
            }
            comp += std::to_string(count) + currentChar;
        }
        return comp;
    }
};