class Solution {
public:
    int solMem(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp){
        int n = grid.size(), m = grid[0].size();
        if(i==n-1 && j==m-1) return grid[i][j];
        if(i>=n || j>=m) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        int r = solMem(grid, i, j+1, dp);
        int d = solMem(grid, i+1, j, dp);
        return dp[i][j] = grid[i][j] + min(r,d);
    }
    int solTab(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        vector<int> curr;
        vector<int> next(m+1, INT_MAX);
        for(int i=n-1; i>=0; i--){
            curr = grid[i]; curr.push_back(INT_MAX);
            for(int j=m-1; j>=0; j--){
                if(j==m-1 && i==n-1){
                    curr[j] = grid[i][j];
                    continue;
                }
                int r = curr[j+1];
                int d = next[j];
                curr[j] = curr[j] + min(r,d);
            }
            next = curr;
        }
        return next[0];
    }
    int sol(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m);
        dp[0] = grid[0][0];
        // First row
        for(int c = 1; c < m; c++) {
            dp[c] = dp[c-1] + grid[0][c];
        }
        // Remaining rows
        for(int r = 1; r < n; r++) {
            // First column
            dp[0] += grid[r][0];

            for(int c = 1; c < m; c++) {
                dp[c] = min(dp[c], dp[c-1]) + grid[r][c];
            }
        }

        return dp[m-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        // int n = grid.size(), m = grid[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solMem(grid, 0,0, dp);
        return sol(grid);
    }
};