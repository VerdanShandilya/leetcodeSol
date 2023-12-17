class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int z=nums.size()/2;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i : m){
            if(i.second>z){
                return i.first;
            }
        }
        return 0;
    }
};