class Solution {
public:
    int helper(vector<vector<int>> &grid,int x,int y,vector<vector<int>> &dp){
        if(x>=grid.size() || y>=grid[x].size() || grid[x][y]==1){
            return 0;
        }
        if(x==grid.size()-1 && y==grid[x].size()-1 && grid[x][y]!=1){
            return 1;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        int a=helper(grid,x+1,y,dp);
        int b=helper(grid,x,y+1,dp);
        return dp[x][y]=a+b;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(),-1));
        return helper(grid,0,0,dp);
    }
};