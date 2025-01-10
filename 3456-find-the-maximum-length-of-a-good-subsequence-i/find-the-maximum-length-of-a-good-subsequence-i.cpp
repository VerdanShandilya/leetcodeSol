class Solution {
public:
    int helper(vector<int>& nums, int k,int index,int prev,vector<vector<vector<int>>> &dp){
        if(index==nums.size()){
            return 0;
        }
        int pick=0;
        if(dp[index][k][prev+1]!=-1){
            return dp[index][k][prev+1];
        }
        if(prev==-1 || nums[index]==nums[prev]){
            pick=1+helper(nums,k,index+1,index,dp);
        }
        else if(k>0){
            pick=1+helper(nums,k-1,index+1,index,dp);
        }
        int notpick=helper(nums,k,index+1,prev,dp);
        return dp[index][k][prev+1]=max(pick,notpick);
    }
    int maximumLength(vector<int>& nums, int k){
        int n=nums.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (k+1,vector<int> (n+1,-1)));
        return helper(nums,k,0,-1,dp);

    }
};