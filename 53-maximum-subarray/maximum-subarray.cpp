class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msum=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            msum=max(msum,sum);
            if(sum<0){
                sum=0;
                continue;
            }
        }
        return msum;
    }
};