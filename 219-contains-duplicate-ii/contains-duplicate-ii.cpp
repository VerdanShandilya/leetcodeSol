class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                if(abs(m[nums[i]]-i)<=k){
                    return true;
                }
                m[nums[i]]=i;
            }
            else{
                m[nums[i]]=i;
            }
        }
        return false;
        
    }
};