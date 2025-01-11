class Solution {
public:
    int helper(vector<int> &nums,int index,int prev,vector<vector<int>> &dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index][prev+1]!=-1){
            return dp[index][prev+1];
        }
        int pick=0;
        if(prev ==-1 || nums[index]>nums[prev]){
            pick=1+helper(nums,index+1,index,dp);
        }
        int nopick=helper(nums,index+1,prev,dp);
        return dp[index][prev+1]=max(pick,nopick);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size()+1,-1));
        return helper(nums,0,-1,dp);
    }
};