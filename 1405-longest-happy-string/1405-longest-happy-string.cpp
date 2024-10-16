class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
         string result;
        vector<pair<int, char>> counts = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        
        while (true) {
            
            sort(counts.begin(), counts.end(), greater<>());
            
        
            bool added = false;
            for (auto &[count, ch] : counts) {
                if (count == 0) break;

                
                if (result.size() >= 2 && result[result.size() - 1] == ch && result[result.size() - 2] == ch)
                    continue;
                
            
                result += ch;
                --count;
                added = true;
                break;
            }
            
            
            if (!added) break;
        }
        
        return result;
    }
};