class Solution {
public:
    int helper(vector<int>& nums, int k){
        int l=0;
        int r=0;
        int ans=0;
        while(r<nums.size()){
            if(nums[r]%2!=0){
                k--;
            }
            while(k<0){
                if(nums[l]%2!=0){
                    k++;
                }
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};