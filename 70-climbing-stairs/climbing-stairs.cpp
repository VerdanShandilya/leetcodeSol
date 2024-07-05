class Solution {
public:
    int ans=0;
    int helper(int n,vector<int> &dp){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int a=helper(n-1,dp);
        int b=helper(n-2,dp);
        dp[n]=a+b;
        return dp[n];
        
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};