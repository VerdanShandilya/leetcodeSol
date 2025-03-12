class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>=0){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        int x=0;
        int y=nums.size()-1;
        while(x<=y){
            int mid=x+(y-x)/2;
            if(nums[mid]<=0){
                x=mid+1;
            }
            else{
                y=mid-1;
            }
        }
        int size1=nums.size()-x;
        int ans=max(l,size1);
        return ans;
    }
};