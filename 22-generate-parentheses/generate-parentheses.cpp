class Solution {
public:

    void helper(int o,int c,vector<string> &ans,string s){
        if(o==0 && c==0){
            ans.push_back(s);
            return;
        }
        if(o<0 || c<0){
            return;
        }
        if(c<=o){
            helper(o-1,c,ans,s+'(');
        }
        else{
            helper(o-1,c,ans,s+'(');
            helper(o,c-1,ans,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        helper(n,n,ans,s);
        return ans;
    }
};