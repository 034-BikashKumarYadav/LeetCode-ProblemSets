class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Loop until all occurrences of `part` are removed
        while ((s.find(part)) != string::npos) {  
            // Find the first occurrence of `part` in `s`
            unsigned idx = s.find(part);   
            
            // Erase `part` from `s` at position `idx` 
            s.erase(idx, part.size());   
        }
        
        // Return the modified string
        return s;
    }
};
