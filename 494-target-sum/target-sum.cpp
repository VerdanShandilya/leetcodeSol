class Solution {
public:
    int count=0;
    void helper(vector<int>& nums, int target,int total,int i){
        if(i<0){
            if(target==total){
                count++;
            }
            return;
        }
        helper(nums,target,total+nums[i],i-1);
        helper(nums,target,total-(nums[i]),i-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        helper(nums,target,0,nums.size()-1);
        return count;
    }
};