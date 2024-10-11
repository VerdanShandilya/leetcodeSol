class Solution {
public:
    bool helper(vector<vector<int>>& grid, int health,int i,int j,vector<vector<bool>> &visited,vector<vector<vector<int>>> &dp){
        if(i<0 || i>grid.size()-1 || j<0 || j>grid[0].size()-1 || visited[i][j] || health<1){
            return false;
        }
        if(grid[i][j]==1){
            health=health-1;
        }
        if(dp[i][j][health]!=-1){
            return dp[i][j][health];
        }
        if(i==grid.size()-1 && j==grid[i].size()-1 && health>=1){
            return true;
        }
        visited[i][j]=true;
        bool path=helper(grid,health,i+1,j,visited,dp)
        || helper(grid,health,i,j+1,visited,dp)
        || helper(grid,health,i-1,j,visited,dp) 
        || helper(grid,health,i,j-1,visited,dp);
        visited[i][j]=false;
        return dp[i][j][health]=path;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>> (grid[0].size(),vector<int>(health+1,-1)));
        return helper(grid,health,0,0,visited,dp);
    }
};