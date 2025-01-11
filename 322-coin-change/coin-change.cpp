class Solution {
public:
    int helper(vector<int>& coins,int index,int amount,vector<vector<int>> &dp){
        if(index>=coins.size() || amount<0){
            return INT_MAX-1;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        if(amount==0){
            return 0;
        }
        int pick=1+helper(coins,index,amount-coins[index],dp);
        int nopick=helper(coins,index+1,amount,dp);
        return dp[index][amount]=min(pick,nopick);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int> (amount+1,-1));
        int ans=helper(coins,0,amount,dp);
        if(ans==INT_MAX-1){
            return -1;
        }
        return ans;
    }
};