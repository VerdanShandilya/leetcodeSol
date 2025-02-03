class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int find=sum-x;
        int l=0;
        int r=0;
        int res=0;
        int ans=INT_MAX;
        while(r<nums.size()){
            res+=nums[r];
            while(l<=r && res>find){
                res-=nums[l];
                l++;
            }
            if(res==find){
                int len=nums.size()-(r-l+1);
                ans=min(ans,len);
            }
            r++;
        }
        if(ans==INT_MAX) 
        return -1;
        return ans;
    }
};