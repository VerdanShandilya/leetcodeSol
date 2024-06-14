class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long count=0;
        for(int i=0;i<nums.size()-1;i++){
            while(nums[i]>=nums[i+1]){
                count++;
                long c=nums[i+1];
                c++;
                nums[i+1]=c;
            }
        }
        return int(count);
    }
};