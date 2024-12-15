class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        double ans=INT_MIN;
        int sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            if(r-l+1==k){
                ans=max(ans,sum/double(k));
                sum-=nums[l];
                l++;
                r++;
            }
            else{
                r++;
            }
        }
        return ans;
    }
};