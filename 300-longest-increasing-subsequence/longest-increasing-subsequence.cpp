class Solution {
private:
    int helper(int n,vector<int> &nums,int curr,int prev,vector<vector<int>> &dp){
        if(curr==n){
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int take=0;
        if(prev==-1 || nums[curr]>nums[prev]){
            take=1+helper(nums.size(),nums,curr+1,curr,dp);
        }
        int notTake=0+helper(nums.size(),nums,curr+1,prev,dp);
        return dp[curr][prev+1]=max(take,notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums){
        vector<vector<int>> dp(nums.size(),vector<int> (nums.size()+1,-1));
        return helper(nums.size(),nums,0,-1,dp);
    }
};