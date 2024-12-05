class Solution {
public:
    bool check(vector<int>& nums) {
        int diff=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                diff++;
            }
        }
        if((diff==1 && nums[0]>=nums[nums.size()-1]) || diff==0){
            return true;
        }
        return false;
    }
};