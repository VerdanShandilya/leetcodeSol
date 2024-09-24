class Solution {
public:
    int helper(vector<int>& nums,int index,vector<int> &dp){
        if(index>=nums.size()-1){
            return 0;
        }
        if(dp[index]!=INT_MAX-1){
            return dp[index];
        }
        int ans=INT_MAX-1;
        for(int i=1;i<=nums[index];i++){
           ans=min(ans,1+helper(nums,index+i,dp));
        }
        return dp[index]=ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),INT_MAX-1);
        return helper(nums,0,dp);
    }
};