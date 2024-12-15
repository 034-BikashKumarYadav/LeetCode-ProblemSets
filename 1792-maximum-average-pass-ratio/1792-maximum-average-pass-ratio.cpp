#include <vector>
#include <queue>
#include <utility> // For std::pair

class Solution {
public:
    double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents) {
        auto compare = [](std::pair<int, int> a, std::pair<int, int> b) {
            double diffA = (double)(a.first + 1) / (a.second + 1) - (double)a.first / a.second;
            double diffB = (double)(b.first + 1) / (b.second + 1) - (double)b.first / b.second;
            return diffA < diffB;
        };

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> maxHeap(compare);

        // Insert all the classes into the priority queue
        for (auto& cls : classes) {
            maxHeap.push({cls[0], cls[1]});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto [pass, total] = maxHeap.top();
            maxHeap.pop();
            pass += 1;
            total += 1;
            maxHeap.push({pass, total});
        }

        // Calculate the resulting maximum average pass ratio
        double maxAvgRatio = 0.0;
        while (!maxHeap.empty()) {
            auto [pass, total] = maxHeap.top();
            maxHeap.pop();
            maxAvgRatio += (double)pass / total;
        }

        return maxAvgRatio / classes.size();
    }
};