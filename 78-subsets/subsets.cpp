class Solution {
public:
    vector<vector<int>> helper(vector<int>& nums,vector<vector<int>> &ans,int i,vector<int> v){
        if(i==nums.size()){
            ans.push_back(v);
            return ans;
        }
        v.push_back(nums[i]);
        helper(nums,ans,i+1,v);
        v.pop_back();
        helper(nums,ans,i+1,v);
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        return helper(nums,ans,0,v);
    }
};