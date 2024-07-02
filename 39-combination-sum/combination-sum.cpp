class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v1;
    void helper(vector<int>& candidates, int target,int i){
        if(target==0){
            ans.push_back(v1);
            return;
        }
        for(int j=i;j<candidates.size();j++){
            v1.push_back(candidates[j]);
            if(candidates[j]<=target)
            helper(candidates,target-candidates[j],j);
            v1.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates,target,0);
        return ans;
    }
};