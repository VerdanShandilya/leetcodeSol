class Solution {
public:
    int robber(vector<int>& nums,vector<int> &dp1,int i){
        if(i>nums.size()-1){
            return 0;
        }
        if(dp1[i]!=-1){
            return dp1[i];
        }
        int a=nums[i]+robber(nums,dp1,i+2);
        int b=robber(nums,dp1,i+1);
        return dp1[i]=max(a,b);
    }
    int rob(vector<int>& nums) {
        if(nums.size()<2){
            return nums[0];
        }
        vector<int> v1(nums.size()-1,0),v2(nums.size()-1,0);
        vector<int> dp1(nums.size()+1,-1),dp2(nums.size()+1,-1);
        for(int i=0;i<nums.size()-1;i++){
            v1[i]=nums[i];
        }
        for(int i=1;i<nums.size();i++){
            v2[i-1]=nums[i];
        }
        int a=robber(v1,dp1,0);
        int b=robber(v2,dp2,0);
        return max(a,b);
    }
};