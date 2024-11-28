class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> obstacles(m, vector<int>(n, INT_MAX));
    obstacles[0][0] = 0;
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 0, 0}); // {obstaclesRemoved, x, y}
    
    vector<int> directionX = {-1, 1, 0, 0};
    vector<int> directionY = {0, 0, -1, 1};
    
    while (!pq.empty()) {
        auto [obs, x, y] = pq.top();
        pq.pop();
        
        if (x == m - 1 && y == n - 1)
            return obs;
        
        for (int d = 0; d < 4; ++d) {
            int newX = x + directionX[d];
            int newY = y + directionY[d];
            
            if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                int newObstacles = obs + grid[newX][newY];
                
                if (newObstacles < obstacles[newX][newY]) {
                    obstacles[newX][newY] = newObstacles;
                    pq.push({newObstacles, newX, newY});
                }
            }
        }
    }
    return -1; 
    }
};