class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            int sum=0;
            int divs=1;
            int msum=0;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i];
                if(sum>mid){
                    divs++;
                    msum=max(msum,sum-nums[i]);
                    sum=nums[i];
                }
            }
            msum=max(msum,sum);
            if(divs<=k){
                ans=msum;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};