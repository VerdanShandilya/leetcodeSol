class Solution {
public:
int mod = 1e9 + 7;
    int helper(vector<vector<int>>& grid, int k, int i, int j, int sum, vector<vector<vector<int>>>& dp) {
        if (i >= grid.size() || j >= grid[i].size()) {
            return 0;
        }
        sum += grid[i][j];
        if (i == grid.size() - 1 && j == grid[i].size() - 1) {
            if(sum % k == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        int rem = sum % k;
        if (dp[i][j][rem] != -1) {
            return dp[i][j][rem];
        }
        int down = helper(grid, k, i + 1, j, sum, dp);
        int right = helper(grid, k, i, j + 1, sum, dp);
        dp[i][j][rem] = (down + right)%mod;
        return dp[i][j][rem];
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return helper(grid, k, 0, 0, 0, dp);
    }
};
