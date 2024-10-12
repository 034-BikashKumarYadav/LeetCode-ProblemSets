class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
         if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> endTimes;

        for (auto& interval : intervals) {
            // If the earliest end time is less than the current start, pop it
            if (!endTimes.empty() && endTimes.top() < interval[0]) {
                endTimes.pop();
            }
            
            endTimes.push(interval[1]);
        }

        return endTimes.size();
        
    }
};