class Solution {
public:
    int fib1(int &n,vector<int> &dp){
        if(n<2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=fib(n-1)+fib(n-2);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return fib1(n,dp);
    }
};