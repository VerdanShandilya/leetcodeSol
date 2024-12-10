class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            bool ls=false;
            bool rs=false;
            if(mid+1<=nums.size()-1){
                if(nums[mid]==nums[mid+1]){
                    rs=true;
                }
            }
            if(mid-1>=0){
                if(nums[mid]==nums[mid-1]){
                    ls=true;
                }
            }
            if(ls==false && rs==false){
                return nums[mid];
            }
            else if(ls){
                if((mid-l-1)%2==0){
                    l=mid+1;
                }
                else{
                    r=mid-2;
                }
            }
            else{
                if((r-mid-1)%2==0){
                    r=mid-1;
                }
                else{
                    l=mid+2;
                }
            }
        }
        return -1;   
    }
};