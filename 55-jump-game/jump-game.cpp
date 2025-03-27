class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(),false);
        dp[nums.size()-1]=true;
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=0;j<nums[i];j++){
                if(i+j+1<dp.size() && dp[j+i+1]==true){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};