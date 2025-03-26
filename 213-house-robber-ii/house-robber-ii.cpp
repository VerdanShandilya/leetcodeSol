class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        vector<int> dp(nums.size()-1);
        vector<int> dp1(nums.size()-1);
        dp[0]=nums[0];
        dp1[0]=nums[1];
        dp[1]=max(nums[1],nums[0]);
        dp1[1]=max(nums[1],nums[2]);
        for(int i=2;i<nums.size()-1;i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        for(int i=3;i<nums.size();i++){
            dp1[i-1]=max(dp1[i-3]+nums[i],dp1[i-2]);
        }
        return max(dp[dp.size()-1],dp1[dp1.size()-1]);
    }
};