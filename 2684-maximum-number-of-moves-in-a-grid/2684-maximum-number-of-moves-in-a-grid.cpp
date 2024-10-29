class Solution {
public:
    vector<vector<int>> directions {{-1,1},{0,1},{1,1}};
    
    int solve(vector<vector<int>> &grid, int i, int j, int currVal,vector<vector<int>> &dp) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j >= n || grid[i][j] <= currVal) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int maxMoves = 0;
        for (auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            maxMoves = max(maxMoves, 1 + solve(grid, new_i, new_j, grid[i][j],dp));
        }

        return dp[i][j]=maxMoves;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        for (int i = 0; i < grid.size(); i++) {
            ans = max(ans, solve(grid, i, 0, -1,dp));
        }
        return ans-1;
    }
};