class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int m=0;
        for(int i=0;i<nums.size();i++){
            m+=nums[i];
            ans=max(ans,m);
            if(m<0){
                m=0;
            }
        }
        return ans;
    }
};