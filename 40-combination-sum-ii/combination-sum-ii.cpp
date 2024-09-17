class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int>>& ans, int index, vector<int>& v) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        if (index > candidates.size() - 1 || target < 0) {
            return;
        }
        if (candidates[index] <= target) {
            v.push_back(candidates[index]);
            helper(candidates, target - candidates[index], ans, index + 1, v);
            v.pop_back();
        }
        while (index + 1 <= candidates.size() - 1 && candidates[index] == candidates[index + 1]) {
            index++;
        }
        helper(candidates, target, ans, index + 1, v);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        helper(candidates, target, ans, 0, v);
        return ans;
    }
};
