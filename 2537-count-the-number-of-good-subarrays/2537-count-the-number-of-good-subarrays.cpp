class Solution {
public:
    long long countGood(vector<int>& nums, int k, long long cnt = 0) {
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> mpp;
            long long pairs = 0;
            for (int left = i; left < nums.size(); left++) {
                pairs += mpp[nums[left]];
                mpp[nums[left]]++;
                if (pairs >= k) cnt++;
            }
        }
        return cnt;
    }
};