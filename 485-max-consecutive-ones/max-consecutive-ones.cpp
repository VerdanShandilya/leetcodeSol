class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int i=0;
        int count=0;
        while(i<nums.size()){
            if(nums[i]==0){
                ans=max(ans,count);
                count=0;
            }
            if(nums[i]==1){
                count++;
            }
            i++;
        }
        ans=max(ans,count);
        return ans;
    }
};