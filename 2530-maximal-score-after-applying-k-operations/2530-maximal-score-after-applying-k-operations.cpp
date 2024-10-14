class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        long long score = 0;

        while (k-- > 0 && !maxHeap.empty()) {
            int top = maxHeap.top();
            maxHeap.pop();
            score += top;
            int newValue = (top + 2) / 3;
            maxHeap.push(newValue);
        }
        return score;
    }
};