class Solution {
public:
    int helper(vector<int>& nums){
        int fans=0;
        int l=0;
        int r=0;
        int ans=0;
        while(r<nums.size()){
            ans+=nums[r];
            if(r-1>=0 && nums[r-1]>=nums[r] ){
                while(l<r){
                    ans-=nums[l];
                    l++;
                }
            }
            fans=max(ans,fans);
            r++;
        }
        return fans;
    }
    int maxAscendingSum(vector<int>& nums) {
        int ans=helper(nums);
        return ans;
    }
};