class Solution {
public:
    int count=0;
    int helper(vector<int>& nums, int target,int total,int i,vector<vector<int>> &dp){
        if(i<0){
            if(target==total){
                count++;
                return 1;
            }
            return 0;
        }
        if(dp[i][total+1000]!=-1){
            return dp[i][total+1000];
        }
        int a=helper(nums,target,total+nums[i],i-1,dp);
        int b=helper(nums,target,total-(nums[i]),i-1,dp);
        return dp[i][total+1000]=a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        vector<vector<int>> dp( nums.size()+1 , vector<int> (2001,-1));  
        for(int i = 0; i < nums.size()+1; i++) { 
            for(int j = 0; j <2001; j++) { 
                dp[i][j] =-1; 
            } 
        } 
        return helper(nums,target,0,nums.size()-1,dp);
    }
};