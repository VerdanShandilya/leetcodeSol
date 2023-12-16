class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==1){
            return;
        }
        k=k%nums.size();
        int z=nums.size();
        vector<int> v;
        for(int i=z-k;i<z;i++){
            v.push_back(nums[i]);
        }
        for(int i=0;i<z-k;i++){
            v.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=v[i];
        }
        return;
    }
};