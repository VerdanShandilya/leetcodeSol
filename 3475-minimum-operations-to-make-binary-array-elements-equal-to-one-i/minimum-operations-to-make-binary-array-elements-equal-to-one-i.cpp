class Solution {
public:
    int minOperations(vector<int>& nums) {
        int l=0;
        int r=0;
        int ans=0;
        while(r<nums.size()){
            if(r-l+1==3){
                if(nums[l]==0){
                    ans++;
                    nums[l]=1;
                    nums[l+1]=!nums[l+1];
                    nums[l+2]=!nums[l+2];
                }
                l++;
                r++;
            }
            else{
                r++;
            }
        }
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum==nums.size())
        return ans;
        else
        return -1;
    }
};