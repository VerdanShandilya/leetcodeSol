class Solution {
public:
    bool helper(vector<int>& nums,int total,int index,vector<vector<int>> &dp){
        if(total<0 || index>nums.size()-1){
            return 0;
        }
        if(total==0){
            return 1;
        }
        if(dp[total][index]!=-1){
            if(dp[total][index]==1)
                return true;
            else
                return false;
        }
        bool a=helper(nums,total-nums[index],index+1,dp);
        bool b=helper(nums,total,index+1,dp);
        return dp[total][index]=a||b;
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(total%2!=0){
            return false;
        }
        total=total/2;
        vector<vector<int>> dp(total+1,vector<int> (nums.size(),-1));
        return helper(nums,total,0,dp);
    }
};