class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
                ans=l;
            }
        }
        return ans;
    }
};