class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int z=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                z++;
            }
            else{
                ans=max(ans,z);
                z=0;
            }
        }
        return max(ans,z);
    }
};