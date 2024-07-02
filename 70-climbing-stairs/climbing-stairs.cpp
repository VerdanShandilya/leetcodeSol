class Solution {
public:
    int helper(int n,unordered_map<int,int> &dp){
        if(n==0 || n==1){
            return 1;
        }
        if(dp.find(n)==dp.end()){
            int one=helper(n-1,dp);
            int two=helper(n-2,dp);
            dp[n]=one+two;
        }
        return dp[n];
    }
    int climbStairs(int n) {
        unordered_map<int,int> dp;
        return helper(n,dp);
    }
};