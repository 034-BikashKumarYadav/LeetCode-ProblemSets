#include <vector>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, 'O')); // 'O' for open space

        // Mark walls
        for (const auto& wall : walls)
            grid[wall[0]][wall[1]] = 'W'; // 'W' for wall

        // Mark guards
        for (const auto& guard : guards)
            grid[guard[0]][guard[1]] = 'G'; // 'G' for guard

        // Directions: left, right, up, down
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        // Mark guarded cells
        auto markGuarded = [&](int x, int y, int dx, int dy) {
            while (true) {
                x += dx, y += dy;
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 'W' || grid[x][y] == 'G')
                    break;
                grid[x][y] = 'U'; // 'U' for unoccupied/unguarded
            }
        };

        // Place guards and extend visibility
        for (const auto& guard : guards) {
            for (const auto& dir : directions)
                markGuarded(guard[0], guard[1], dir.first, dir.second);
        }

        // Count unguarded cells
        int unguardedCount = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'O')
                    ++unguardedCount;
            }
        }

        return unguardedCount;
    }
};