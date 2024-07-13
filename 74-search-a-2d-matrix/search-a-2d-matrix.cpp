class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int i=0;
        int j=nums[0].size()-1;
        while(i>=0 && i<nums.size() && j>=0 && j<nums[0].size()){
            if(nums[i][j]==target){
                return true;
            }
            else if(nums[i][j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};