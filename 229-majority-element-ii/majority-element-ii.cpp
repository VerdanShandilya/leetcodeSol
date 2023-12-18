class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int> v;
        for(auto i : m){
            if(i.second>nums.size()/3){
                v.push_back(i.first);
            }
        }
        return v;
    }
};