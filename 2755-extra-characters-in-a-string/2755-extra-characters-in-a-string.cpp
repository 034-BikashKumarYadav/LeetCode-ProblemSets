class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
         std::unordered_set<std::string> dictSet(dictionary.begin(), dictionary.end());
        int n = s.length();
        std::vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                std::string substring = s.substr(j, i - j);
                if (dictSet.count(substring) > 0) {
                    dp[i] = std::min(dp[i], dp[j]);
                }
                else {
                    dp[i] = std::min(dp[i], dp[j] + (i - j));
                }
            }
        }

        return dp[n];
        
    }
};