class Solution {
public:
    int bs(vector<int>& nums, int k,int l,int r){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==k){
                return mid;
            }
            else if(nums[mid]>k){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return max(bs(nums,target,0,r),bs(nums,target,r,nums.size()-1));
    }
};