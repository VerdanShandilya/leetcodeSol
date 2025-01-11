class Solution {
public: 
    int helper(vector<int> &nums,int index,vector<int> &dp){
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
        vector<int> dp1(nums.size()+1,-1);
        vector<int> dp2(nums.size()+1,-1);
        if (nums.size() == 1) return nums[0];
        vector<int> a(nums.begin()+1,nums.end());
        vector<int> b(nums.begin(),nums.end()-1);
        int ans1=helper(a,0,dp1);
        int ans2=helper(b,0,dp2);
        return max(ans1,ans2);
    }
};