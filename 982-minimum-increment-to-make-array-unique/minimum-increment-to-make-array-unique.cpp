class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long count=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]>0){
                continue;
            }
            else{
                long c=abs(nums[i+1]-nums[i]);
                c+=1;
                nums[i+1]=nums[i+1]+c;
                count+=c;
            }
        }
        return count;
    }
};