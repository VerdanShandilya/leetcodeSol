class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid =l+(r-l)/2;
            int next=(mid+1)%nums.size();
            int prev=(mid+nums.size()-1)%nums.size();
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
                return nums[mid];
            }
            else if(nums[mid]>=nums[0]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return nums[0];
    }
};