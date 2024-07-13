class Solution {
public:
    int search(vector<int>& nums, int target) {
        int seprator=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                seprator=i;
                break;
            }
        }
        int i=0;
        int j=seprator;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        i=seprator+1;
        j=nums.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return -1;
    }
};