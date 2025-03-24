class Solution {
public:
    void helper(vector<int>& nums,vector<int> v,vector<vector<int>> &ans,int index){
        if(index>=nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<=v.size();i++){
            v.insert(v.begin()+i,nums[index]);
            helper(nums,v,ans,index+1);
            v.erase(v.begin()+i);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(nums,v,ans,0);
        return ans;
    }
};