class Solution {
public:
    map<int,int>dp;
    int helper(long n){
        if(n<1){
            return INT_MAX;
        }
        if(n==1){
            return 0;
        }
        if(dp[n]!=0){
            return dp[n];
        }
        int a=INT_MAX;
        int b=INT_MAX;
        int c=INT_MAX;
        if(n%2==0){
            a=1+helper(n/2);
        }
        else{
            b=1+helper(n+1);
            c=1+helper(n-1);
        }
        return dp[n]=min({a,b,c});
    }
    int integerReplacement(int n) {
        return helper(n);
    }
};