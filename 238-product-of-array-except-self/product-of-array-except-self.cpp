class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int p=1;
        for(int i=0;i<nums.size();i++){
            ans[i]=p;
            p=p*nums[i];
        }
        p=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]=ans[i]*p;
            p=p*nums[i];
        }
        return ans;
    }
};