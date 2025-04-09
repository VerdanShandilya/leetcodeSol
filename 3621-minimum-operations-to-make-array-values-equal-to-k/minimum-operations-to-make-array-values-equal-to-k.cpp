class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;
        for(auto i : nums){
            s.insert(i);
        }
        int ans=0;
        for(auto i : s){
            if(i>k){
                ans++;
            }
            else if(i<k){
                return -1;
            }
        }
        return ans;
    }
};