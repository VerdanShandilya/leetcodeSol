class Solution {
public:
    vector<vector<int>> ans;
    void helper(int n, int k,int j,vector<int> &v1){
        if(v1.size()==k){
            ans.push_back(v1);
            return;
        }
        for(int i=j;i<=n;i++){
            v1.push_back(i);
            helper(n,k,i+1,v1);
            v1.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v1;
        helper(n,k,1,v1);
        return ans;  
    }
};
