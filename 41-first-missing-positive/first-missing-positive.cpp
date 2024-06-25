class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,bool> mp;
        int maxi = *max_element(nums.begin(), nums.end());
        for(auto &num : nums){
            mp[num] = true;
        }
        for(int i=1; i<maxi; i++){
            if(mp.find(i) == mp.end())
                return i;
        }
        return maxi < 0 ? 1 : maxi+1;
    }
};