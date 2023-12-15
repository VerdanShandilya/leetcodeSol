class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        // nums.erase(nums.begin(),nums.end());
        int z=0;
        for(auto i : s){
            nums[z]=i;
            z++;
        }
        return z;
    }
};