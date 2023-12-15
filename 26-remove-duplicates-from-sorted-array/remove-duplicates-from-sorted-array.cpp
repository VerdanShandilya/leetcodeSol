class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int z=0;
        for(auto i : s){
            nums[z]=i;
            z++;
        }
        return z;
    }
};