class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r=nums.size()-1;
        while(nums[0]>nums[r]){
            r--;
        }
        int low=0;
        int high=r;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        low=r+1;
        high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};