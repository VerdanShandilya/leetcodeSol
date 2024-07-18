class Solution {
public:
    int helper(vector<int>& prices,int i,int buy,vector<vector<int>> &dp){
        if(i>prices.size()-1){
            return 0;
        }
        int profit=0;
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        if(buy==1){
            int buy=-prices[i]+helper(prices,i+1,0,dp);
            int notbuy=helper(prices,i+1,1,dp);
            profit=max(buy,notbuy);
        }
        else{
            int sell=prices[i]+helper(prices,i+2,1,dp);
            int notsell=helper(prices,i+1,0,dp);
            profit=max(sell,notsell);
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper(prices,0,1,dp);
    }
};