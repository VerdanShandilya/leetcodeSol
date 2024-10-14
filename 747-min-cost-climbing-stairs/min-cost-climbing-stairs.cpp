class Solution {
public:
    int helper(int i,vector<int>& cost, vector<int>& dp){
        if(i<=1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i] = min(cost[i-1]+helper(i-1,cost,dp), cost[i-2]+helper(i-2,cost,dp));
        }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        return helper(cost.size(),cost,dp);
    }
};