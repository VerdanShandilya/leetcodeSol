class Solution {
public:
    void dfs(int curr,int &n,vector<int> &ans){
        if(curr> n){
            return;
        }
        ans.push_back(curr);
        for(int i=0;i<10;i++){
            int temp=curr*10+i;
            dfs(temp,n,ans);
        }
        if(curr<9){
            curr++;
            dfs(curr,n,ans);
        } 
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        dfs(1,n,ans);
        return ans;
    }
};