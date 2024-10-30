class Solution {
public:
    void helper(vector<int>& nums,set<vector<int>> &s,int index,vector<int> &v){
        if(index>=nums.size()){
            s.insert(v);
            return;
        }
        v.push_back(nums[index]);
        helper(nums,s,index+1,v);
        v.pop_back();
        helper(nums,s,index+1,v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        helper(nums,s,0,v);
        for (auto i : s) {
            ans.push_back(i);
        }
        return ans;
    }
};