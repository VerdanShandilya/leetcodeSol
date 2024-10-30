class Solution {
public:
    int helper(vector<vector<int>>& dungeon,int x,int y,vector<vector<int>> &dp){
        if(x==dungeon.size()-1 && y==dungeon[x].size()-1){
            if(dungeon[x][y]<=0){
                return abs(dungeon[x][y])+1;
            }
            else{
                return 1;
            }
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        if(x>=dungeon.size() || y>=dungeon[x].size()){
            return INT_MAX;
        }
        int a=helper(dungeon,x+1,y,dp);
        int b=helper(dungeon,x,y+1,dp);
        int ans=-dungeon[x][y]+min(a,b);
        if(ans<=0)
        return dp[x][y]=1;
        return dp[x][y]=ans;

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size()+1,vector<int> (dungeon[0].size()+1,-1));
        return helper(dungeon,0,0,dp);
    }
};
