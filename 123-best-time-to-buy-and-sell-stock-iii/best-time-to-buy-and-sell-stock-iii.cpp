class Solution {
public:
    int helper(vector<int>& prices,bool a, int index,int trans,vector<vector<vector<int>>> &dp){
        if(index>=prices.size() || trans>=2){
            return 0;
        }
        if(dp[index][a][trans]!=-1){
            return dp[index][a][trans];
        }
        int ans=0;
        if(a){
            int buy=-prices[index]+helper(prices,!a,index+1,trans,dp);
            int notbuy=helper(prices,a,index+1,trans,dp);
            ans=max(buy,notbuy);
        }
        else{
            int sell=prices[index]+helper(prices,!a,index+1,trans+1,dp);
            int notsell=helper(prices,a,index+1,trans,dp);
            ans=max(sell,notsell);
        }
        return dp[index][a][trans]=ans;

    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>> (2, vector<int> (3,-1)));
        bool a=true;
        return helper(prices,a,0,0,dp);
    }
};