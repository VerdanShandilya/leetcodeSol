class Solution {
public:
    int helper(vector<int>& prices,int index,int a,int nb,vector<vector<vector<int>>> &dp){
        if(index>=prices.size() || nb==0){
            return 0;
        }
        if(dp[index][a][nb]!=-1){
            return dp[index][a][nb];
        }
        int profit=0;
        if(a==0){
            int buy=-prices[index]+helper(prices,index+1,1,nb,dp);
            int notbuy=helper(prices,index+1,0,nb,dp);
            profit=max(buy,notbuy);
        }
        else{
            int sell=prices[index]+helper(prices,index+1,0,nb-1,dp);
            int notsell=helper(prices,index+1,1,nb,dp);
            profit=max(sell,notsell);
        }
        return dp[index][a][nb]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>> (2,vector<int> (k+1,-1)));
        return helper(prices,0,0,k,dp);
    }
};