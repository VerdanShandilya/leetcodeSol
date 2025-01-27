class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        if(k==0){
            return false;
        }
        unordered_map<int,int> m;
        while(r<nums.size()){
            if(r-l<k){
                if(m.find(nums[r])==m.end()){
                    m[nums[r]]=r;
                    r++;
                }
                else{
                    return true;
                }
            }
            else if(r-l==k){
                if(m.find(nums[r])==m.end()){
                    m.erase(nums[l]);
                    m[nums[r]]=r;
                    l++;
                    r++;
                }
                else{
                    return true;
                }
            }
            else{
                r++;
            }
        }
        return false;
    }
};