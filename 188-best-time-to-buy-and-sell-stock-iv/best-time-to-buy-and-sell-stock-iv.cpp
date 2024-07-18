class Solution {
public:
    int helper(int k, vector<int>& prices,int i,int buy,vector<vector<vector<int>>> &dp){
        if(i==prices.size() || k==0){
            return 0;
        }
        int profit=0;
        if(dp[i][k][buy]!=-1){
            return dp[i][k][buy];
        }
        if(buy==1){
            int buy=-prices[i]+helper(k,prices,i+1,0,dp);
            int notbuy=helper(k,prices,i+1,1,dp);
            profit=max(buy,notbuy);
        }
        else{
            int sell=prices[i]+helper(k-1,prices,i+1,1,dp);
            int notsell=helper(k,prices,i+1,0,dp);
            profit=max(sell,notsell);
        }
        return dp[i][k][buy]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(k+1,vector<int> (2,-1)));
        return helper(k,prices,0,1,dp);
    }
};