class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int i=0;int z=0;
        int j=1;
        int count=0;
        while(z<nums.size() && i<j){
            if(nums[i]+nums[j]<target){
                count++;
            }
            if(j==nums.size()-1){
                i++;
                j=i+1;
                z=j;
                continue;
            }
            j++;
            z++;
        }
        return count;
    }
};