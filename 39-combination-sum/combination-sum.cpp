class Solution {
public:
    void helper(vector<int>& candidates,int target,int index,vector<vector<int>> &ans,
    vector<int> &v){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(index>=candidates.size() || target<0){
            return;
        }
        v.push_back(candidates[index]);
        helper(candidates,target-candidates[index],index,ans,v);
        v.pop_back();
        helper(candidates,target,index+1,ans,v);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(candidates,target,0,ans,v);
        return ans;
    }
};