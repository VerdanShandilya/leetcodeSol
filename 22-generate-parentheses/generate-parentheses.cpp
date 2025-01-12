class Solution {
public:
    void helper(int i,int j,string a,vector<string> &ans){
        if(i==0 && j==0){
            ans.push_back(a);
            return;
        }
        if(i>0){
            helper(i-1,j,a+'(',ans);
        }
        if(i<j){
            helper(i,j-1,a+')',ans);
        }    
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n,n,"",ans);
        return ans;
    }
};