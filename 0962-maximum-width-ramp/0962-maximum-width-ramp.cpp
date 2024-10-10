class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> indices(n);
        
        // Fill indices with values 0 to n-1
        for (int i = 0; i < n; ++i) {
            indices[i] = i;
        }
        
        // Sort indices based on the values in nums array
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            if (nums[a] == nums[b]) return a < b;  // Sort by index if values are equal
            return nums[a] < nums[b];
        });
        
        int maxRamp = 0;
        int minIndex = indices[0];  // Track the smallest index found so far
        
        // Iterate through the sorted indices
        for (int i = 1; i < n; ++i) {
            int currentIndex = indices[i];
            
            // Calculate the ramp width for the current pair of indices
            maxRamp = max(maxRamp, currentIndex - minIndex);
            
            // Update the minimum index encountered so far
            minIndex = min(minIndex, currentIndex);
        }
        
        return maxRamp;
    }
};