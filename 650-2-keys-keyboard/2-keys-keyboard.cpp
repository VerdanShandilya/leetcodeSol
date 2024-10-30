class Solution {
public:
    int helper(int n,int count,int c,vector<vector<int>> &dp){
        if(n==count){
            return 0;
        }
        if(count>n){
            return 10000;
        }
        if(dp[count][c]!=-1){
            return dp[count][c];
        }
        int copy=2+helper(n,count+count,count,dp);
        int paste=1+helper(n,count+c,c,dp);
        return dp[count][c]=min(copy,paste);
    }
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        vector<vector<int>> dp(1001,vector<int> (1001,-1));
        return 1+helper(n,1,1,dp);
    }
};