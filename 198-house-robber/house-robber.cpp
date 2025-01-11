class Solution {
public:
    int helper(vector<int>& nums,int index,vector<int> &dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int rob=nums[index]+helper(nums,index+2,dp);
        int norob=helper(nums,index+1,dp);
        return dp[index]=max(rob,norob);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums,0,dp);
    }
};