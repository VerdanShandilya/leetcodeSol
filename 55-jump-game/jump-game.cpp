class Solution {
public:
    bool helper(vector<int>& nums,vector<int> &dp,int index){
        if(index>nums.size()-1){
            return false;
        }
        if(dp[index]!=-1){
            if(dp[index]==1)
            return true;
            else
            return false;
        }
        if(index==nums.size()-1){
            return true;
        }
        for(int i=1;i<=nums[index];i++){
            bool a=helper(nums,dp,index+i);
            if(a==true){
                dp[index+i]=1;
                return true;
            }
            
        }
        dp[index]=0;
        return dp[index];
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums,dp,0);
    }
};