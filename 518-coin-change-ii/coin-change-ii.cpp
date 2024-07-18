class Solution {
public:
    int helper(vector<int>& coins, int amount,int i,vector<vector<int>> &dp){
        if(amount==0){
            return 1;
        }
        if(i>coins.size()-1){
            return 0;
        }
        if(dp[amount][i]!=-1){
            return dp[amount][i];
        }
        int a=0;
        if(amount-coins[i]>=0){
           a=helper(coins,amount-coins[i],i,dp);
        }
        int b=helper(coins,amount,i+1,dp);
        return dp[amount][i]=a+b;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp( amount+1, vector<int> (coins.size(),-1));  
        return helper(coins,amount,0,dp);
    }
};