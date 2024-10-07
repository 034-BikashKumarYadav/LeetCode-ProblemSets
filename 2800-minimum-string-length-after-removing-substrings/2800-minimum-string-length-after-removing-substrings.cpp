class Solution {
public:
    int minLength(string s) {
        int i = 0;  // Pointer for iterating through the string
    int n = s.length();
    
    while (i < n - 1) {
        if ((s[i] == 'A' && s[i + 1] == 'B') || (s[i] == 'C' && s[i + 1] == 'D')) {
            // Remove the occurrence of "AB" or "CD" from the string
            s.erase(i, 2);
            i = std::max(0, i - 1);  // Move the pointer back by 1 position
            n -= 2;  // Adjust the length of the string
        } else {
            i++;  // Move the pointer to the next character
        }
    }
    
    return n;
        
    }
};