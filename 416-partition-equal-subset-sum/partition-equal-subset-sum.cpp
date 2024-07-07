class Solution {
public:
    bool helper(vector<int>& nums,int total,int index,vector<vector<int>> &dp){
        if(index>nums.size()-1){
            return 0;
        }
        if(total==0){
            return true;
        }
        bool a;
        bool b;
        if(dp[total] [index]!=-1){
            if(dp[total][index]==1){
                return true;
            }
            return false;
        }
        if(nums[index]<=total){
            a=helper(nums,total-nums[index],index+1,dp);
        }
        b=helper(nums,total,index+1,dp);
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
        vector<vector<int>> dp( total+1 , vector<int> (nums.size()));  
        for(int i = 0; i < total+1; i++) { 
            for(int j = 0; j < nums.size(); j++) { 
                dp[i][j] =-1; 
            } 
        } 
       return helper(nums,total,0,dp);
    }
};