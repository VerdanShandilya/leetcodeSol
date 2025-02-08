class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> m;
        int l=0;
        int r=0;
        int ans=0;
        int cans=0;
        while(r<nums.size()){
            m[nums[r]]++;
            cans+=nums[r];
            while(m[nums[r]]>1){
                cans-=nums[l];
                m[nums[l]]--;
                l++;
            }
            ans=max(ans,cans);
            r++;
        }
        return ans;
    }
};