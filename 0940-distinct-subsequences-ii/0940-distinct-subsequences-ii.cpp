class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        // last[c] stores the dp value BEFORE the previous occurrence of character c
        vector<long long> last(26, 0);
        long long dp = 1; // count of distinct subsequences including empty
        
        for (char c : s) {
            int idx = c - 'a';
            // Each existing subsequence can either take c or not -> 2 * dp
            // Subtract subsequences that already ended with c to avoid duplicates
            long long new_dp = (2 * dp - last[idx] + MOD) % MOD;
            // Update last[idx] to the dp value before this character was added
            last[idx] = dp;
            dp = new_dp;
        }
        // Exclude the empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};