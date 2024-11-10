class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==1 && nums[0]==val){
            return 0;
        }
        if(nums.size()<2){
            return nums.size();
        }
        int i=0;
        int j=1;
        while(j<nums.size()){
            if(nums[i]==val && nums[j]==val){
                j++;
            }
            else if(nums[i]==val && nums[j]!=val){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        for(int k=0;k<nums.size();k++){
            if(nums[k]==val){
                return k;
            }
        }
        return nums.size();
    }
};