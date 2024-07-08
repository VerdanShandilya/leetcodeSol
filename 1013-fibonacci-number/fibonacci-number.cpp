class Solution {
public:
    int dp[31]={0};
    int fib(int n) {
        if(n<2){
            return n;
        }
        if(dp[n]!=0){
            return dp[n];
        }
        return dp[n]=fib(n-1)+fib(n-2);
    }
};