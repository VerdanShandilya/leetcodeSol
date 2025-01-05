class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=nums.size()-3;
        int max=0;
        while(i>=0){
            if(nums[i]+nums[i+1]>nums[i+2] && nums[i+1]+nums[i+2]>nums[i] && nums[i]+nums[i+2]>nums[i+1]){
                max=nums[i]+nums[i+1]+nums[i+2];
                return max;
            }
            i--;
        }
        return max;
    }
};