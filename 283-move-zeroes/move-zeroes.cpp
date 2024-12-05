class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        while(i<nums.size() && nums[i]!=0){
            i++;
        }
        int j=i+1;
        while(j<nums.size()){
            if(nums[j]!=0){
                nums[i]=nums[j];
                nums[j]=0;
            }
            j++;
            while(nums[i]!=0){
                i++;
            }
        }
        return ;
    }
};