class Solution {
public:
    int helper(vector<int>& prices, int fee,int i,int buy,vector<vector<int>> &dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int profit=0;
        if(buy==1){
            int buy=-prices[i]+helper(prices,fee,i+1,0,dp);
            int notbuy=helper(prices,fee,i+1,1,dp);
            profit=max(buy,notbuy);
        }
        else{
            int sell=prices[i]-fee+helper(prices,fee,i+1,1,dp);
            int notsell=helper(prices,fee,i+1,0,dp);
            profit=max(sell,notsell);
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper(prices,fee,0,1,dp);
    }
};