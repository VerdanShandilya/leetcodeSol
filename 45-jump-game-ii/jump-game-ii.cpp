class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[nums.size()-1]=0;
        for(int i=nums.size()-2;i>=0;i--){
            int m=INT_MAX-1;
            for(int j=0;j<nums[i];j++){
                if(i+j+1>=nums.size()){
                    break;
                }
                m=min(m,1+dp[i+j+1]);
            }
            dp[i]=m;
        }
        return dp[0];
    }
};