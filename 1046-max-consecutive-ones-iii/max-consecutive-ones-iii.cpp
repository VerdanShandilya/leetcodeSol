class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int ans=0;
        int count=0;
        while(r<nums.size()){
            if(nums[r]==1)
            count++;
            if(nums[r]==0 && k==0){
                while(k==0){
                    if(nums[l]==0){
                        k++;
                    }
                    l++;
                    count--;
                }
            }
            if(nums[r]==0 && k>0){
                count++;
                k--;
            }
            ans=max(ans,count);
            r++;
        }
        return ans;
    }
};