class Solution {
public:
    int helper(vector<int>& nums, int k){
        unordered_map<int,int> m;
        int uniq=0;
        int l=0;
        int r=0;
        int ans=0;
        while(r<nums.size()){
            m[nums[r]]++;
            if(m[nums[r]]==1){
                uniq++;
            }
            while(uniq>k){
                m[nums[l]]--;
                if(m[nums[l]]==0){
                    uniq--;
                }
                l++;
            }
            if(uniq<=k){
                ans+=r-l+1;
            }
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};