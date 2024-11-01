class Solution {
public:
    int helper(vector<int>& prices,int index,int a,vector<vector<int>> &dp){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][a]!=-1){
            return dp[index][a];
        }
        int buy=0;
        int notbuy=0;
        int sell=0;
        int notsell=0;
        if(a==0){
            buy=-prices[index]+helper(prices,index+1,1,dp);
            notbuy=helper(prices,index+1,0,dp);
        }
        else{
            sell=prices[index]+helper(prices,index+1,0,dp);
            notsell=helper(prices,index+1,1,dp);
        }
        return dp[index][a]=max({buy,notbuy,sell,notsell});
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int> (2,-1));
        return helper(prices,0,0,dp);
    }
};