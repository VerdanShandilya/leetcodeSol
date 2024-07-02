class Solution {
public:
    int ans=INT_MIN;
    int helper(vector<int>& nums,int i,vector<int> &dp){
        if(i==nums.size()-1){
            return nums[i];
        }
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int pick=nums[i]+helper(nums,i+2,dp);
        int nopick=helper(nums,i+1,dp);
        dp[i]=max(pick,nopick);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums,0,dp);
    }
};