class Solution {
public:
    int helper(vector<int>& nums,vector<int>& dp,int index){
        if(index>nums.size()-1){
            return 0;
        }
        if(index==nums.size()-1){
            return nums[index];
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int one=nums[index]+helper(nums,dp,index+2);
        int two=helper(nums,dp,index+1);
        dp[index]=max(one,two);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums,dp,0);
    }
};