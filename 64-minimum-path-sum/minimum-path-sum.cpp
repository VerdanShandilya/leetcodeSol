class Solution {
public:
    int path(int a,int b,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(a>grid.size()-1 || b>grid[0].size()-1){
            return 1e9;
        }
        if(a==grid.size()-1&&b==grid[0].size()-1){
            return grid[a][b];
        }
        if(dp[a][b]!=-1){
            return dp[a][b];
        }
        int i=grid[a][b]+path(a,b+1,grid,dp);
        int j=grid[a][b]+path(a+1,b,grid,dp);
        return dp[a][b]=min(i,j);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp( grid.size(), vector<int> (grid[0].size()));  
        for(int i = 0; i < grid.size(); i++) { 
            for(int j = 0; j < grid[0].size(); j++) { 
                dp[i][j] =-1; 
            } 
        } 
        return path(0,0,grid,dp);
        
    }
};