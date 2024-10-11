#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<tuple<int, int, int>> events;
        
        // Collect all events for arrival and departure
        for (int i = 0; i < n; ++i) {
            events.emplace_back(times[i][0], 1, i);  // Arrival event
            events.emplace_back(times[i][1], 0, i);  // Leaving event
        }
        
        // Sort events by time, prioritize leave over arrive at the same time
        sort(events.begin(), events.end());
        
        // Min-heap for available chairs and map for assigned chairs
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        vector<int> assignedChair(n, -1);
        
        // Initialize chairs
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i);
        }
        
        for (const auto& [time, type, friendIndex] : events) {
            if (type == 1) { // Arrival
                int chair = availableChairs.top();
                availableChairs.pop();
                assignedChair[friendIndex] = chair;
                
                if (friendIndex == targetFriend) {
                    return chair;
                }
            } else { // Departure
                int chair = assignedChair[friendIndex];
                availableChairs.push(chair);
            }
        }
        
        return -1; // Should never reach here
    }
};