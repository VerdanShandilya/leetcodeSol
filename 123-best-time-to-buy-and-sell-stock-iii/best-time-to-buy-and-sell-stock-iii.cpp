class Solution {
public:
    int helper(vector<int>& prices,int i,int k,int buy,vector<vector<vector<int>>> &dp){
        if(i==prices.size() || k==0){
            return 0;
        }
        int profit=0;
        if(dp[i][buy][k]!=-1){
            return dp[i][buy][k];
        }
        if(buy==1){
            int buy=-prices[i]+helper(prices,i+1,k,0,dp);
            int notbuy=helper(prices,i+1,k,1,dp);
            profit=max(buy,notbuy);
        }
        else{
            int sell=prices[i]+helper(prices,i+1,k-1,1,dp);
            int notsell=helper(prices,i+1,k,0,dp);
            profit=max(sell,notsell);
        }
        return dp[i][buy][k]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(prices,0,2,1,dp);
    }
};