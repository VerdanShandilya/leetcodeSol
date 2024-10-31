class Solution {
public:
    int helper(vector<vector<int>>& matrix,int x,int y,vector<vector<int>> &dp){
        if(x<0 || y<0 || x>=matrix.size() || y>=matrix.size()){
            return 10000001;
        }
        if(x==matrix.size()-1){
            return matrix[x][y];
        }
        if(dp[x][y]!=-2){
            return dp[x][y];
        }
        int a=helper(matrix,x+1,y-1,dp);
        int b=helper(matrix,x+1,y,dp);
        int c=helper(matrix,x+1,y+1,dp);
        return dp[x][y]=matrix[x][y]+min(a,min(b,c));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int> (matrix.size(),-2));
        int ans=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            ans=min(ans,helper(matrix,0,i,dp));
        }
        return ans;
    }
};

