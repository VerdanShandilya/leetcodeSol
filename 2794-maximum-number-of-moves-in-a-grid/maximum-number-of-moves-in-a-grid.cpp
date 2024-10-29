class Solution {
public:
    int helper(vector<vector<int>>& grid,int x,int y,vector<vector<int>> &dp){
        if(x>=grid.size() || y>=grid[x].size()){
            return 0;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        int a=0;
        int b=0;
        int c=0;
        if(x-1>=0 && y+1<=grid[x].size()-1 && grid[x-1][y+1]>grid[x][y])
            a=1+helper(grid,x-1,y+1,dp);
        if(y+1<=grid[x].size()-1 && grid[x][y+1]>grid[x][y])
            b=1+helper(grid,x,y+1,dp);
        if(x+1<=grid.size()-1 && y+1<=grid[x].size()-1 && grid[x+1][y+1]>grid[x][y])
            c=1+helper(grid,x+1,y+1,dp);
        return dp[x][y]=max(a,max(b,c));
    }
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+1,vector<int> (grid[0].size()+1,-1));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            ans=max(ans,helper(grid,i,0,dp));
        }
        return ans;
    }
};