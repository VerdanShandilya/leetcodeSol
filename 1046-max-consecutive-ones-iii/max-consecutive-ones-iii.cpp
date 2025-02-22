class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count=0;
        int l=0;
        int r=0;
        int ans=0;
        while(r<nums.size()){
            if(nums[r]==0){
                count++;
            }
            while(count>k){
                if(nums[l]==0){
                    count--;
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};