class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int r=0;
        int ans=INT_MAX;
        int sum=0;
        int count=0;
        while(r<nums.size()){
            sum+=nums[r];
            count++;
            if(sum>=target){
                while(sum>=target){
                    ans=min(ans,count);
                    sum-=nums[l];
                    l++;
                    count--;
                }
            }
            r++;
        }
        if(ans==INT_MAX)
        return 0;
        return ans;
    }
};