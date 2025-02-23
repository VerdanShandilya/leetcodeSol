class Solution {
public:
    void helper(vector<vector<int>>& g,vector<vector<int>> &ans,vector<int> &v,int node){
        v.push_back(node);
        if(node==g.size()-1){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<g[node].size();i++){
            helper(g,ans,v,g[node][i]);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(g,ans,v,0);
        return ans;
    }
};