class Solution {
public:
    int helper(vector<int> &nums,int curr,int prev,vector<vector<int>> &dp){
        if(curr>=nums.size()){
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int pick=0;
        if(prev==-1 || nums[curr]>nums[prev]){
            pick=1+helper(nums,curr+1,curr,dp);
        }
        int nopick=helper(nums,curr+1,prev,dp);
        return dp[curr][prev+1]=max(pick,nopick);
    }
    int lengthOfLIS(vector<int>& nums){
        vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size(),-1));
        return helper(nums,0,-1,dp);
    }
};