class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
           
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        int maxVal = INT_MIN;

        
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }

        int start = 0, end = INT_MAX;

        
        while (true) {
            auto [minVal, range] = minHeap.top();
            minHeap.pop();
            int listIndex = range.first, eleIndex = range.second;
            
            
            if (maxVal - minVal < end - start) {
                start = minVal;
                end = maxVal;
            }
            
            
            if (eleIndex + 1 == nums[listIndex].size()) break;

            
            int nextVal = nums[listIndex][eleIndex + 1];
            minHeap.push({nextVal, {listIndex, eleIndex + 1}});
            maxVal = max(maxVal, nextVal);
        }

        return {start, end};
        
    }
};