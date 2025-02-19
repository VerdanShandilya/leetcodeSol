class Solution {
public:
    int helper(vector<int> &coins,int index,int amount,vector<vector<int>> &dp){
        if(amount==0){
            return 0;
        }
        if(index>=coins.size()){
            return INT_MAX-1;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }

        int a=INT_MAX;
        if(amount-coins[index]>=0){
            a=1+helper(coins,index,amount-coins[index],dp);
        }
        int c=helper(coins,index+1,amount,dp);
        return dp[index][amount]=min(a,c);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        int ans=helper(coins,0,amount,dp);
        if(ans==INT_MAX-1){
            return -1;
        }
        return ans;
    }
};