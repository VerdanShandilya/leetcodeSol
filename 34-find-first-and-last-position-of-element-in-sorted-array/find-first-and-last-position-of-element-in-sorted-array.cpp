class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==1 && nums[0]==target){
            return {0,0};
        }
        int l=0;
        int r=nums.size()-1;
        int first=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                while(mid>=0 && nums[mid]==target){
                    mid--;
                }
                first=mid+1;
                break;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        int last=-1;
        l=0;
        r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;;
            if(nums[mid]==target){
                while(mid <nums.size() && nums[mid]==target){
                    mid++;
                }
                last=mid-1;
                break;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return {first,last};
    }
};