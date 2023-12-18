class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        for(int x=0;x<nums.size();x++){
            for(int y=0;y<x;y++){
                swap(nums[x][y],nums[y][x]);
            }
        }
        for(int i=0;i<nums.size();i++){
            reverse(nums[i].begin(),nums[i].end());
        }
        return;
    }
};