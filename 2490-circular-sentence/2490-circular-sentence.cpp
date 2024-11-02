class Solution {
public:
    bool isCircularSentence(string sentence) {
         int n = sentence.size();
        
        if (n == 0) return true;
        
        char firstChar = sentence[0];
        char lastChar = sentence[n - 1];
        
        if (firstChar != lastChar) return false;
        
        for (int i = 0; i < n; ++i) {
            if (sentence[i] == ' ' && i + 1 < n) {
                // Compare the last character before space with the first character after space
                if (sentence[i - 1] != sentence[i + 1]) {
                    return false;
                }
            }
        }
        return true;
        
    }
};