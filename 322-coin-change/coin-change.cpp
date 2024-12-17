class Solution {
public:
    int helper(vector<int>& coins, int amount,int index,vector<vector<int>> &dp){
        if(amount<0 || index>coins.size()-1){
            return INT_MAX-1;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        if(amount==0){
            return 0;
        }
        int a=1+helper(coins,amount-coins[index],index,dp);
        int b=helper(coins,amount,index+1,dp);
        return dp[index][amount]=min(a,b);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        int ans=helper(coins,amount,0,dp);
        if(ans==INT_MAX-1){
            return -1;
        }
        return ans;
    }
};