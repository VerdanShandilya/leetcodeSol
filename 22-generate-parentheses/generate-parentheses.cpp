class Solution {
public:
    vector<string> helper(vector<string> &ans,int o,int c,string a){
        if(o==0 && c==0){
            ans.push_back(a);
            return ans;
        }
        if(o==c){
            helper(ans,o-1,c,a+'(');
        }
        else if(o==0){
           helper(ans,o,c-1,a+')'); 
        }
        // else if(c==0){
        //     helper(ans,o-1,c,a+'(');
        // }
        else{
            helper(ans,o-1,c,a+'(');
            helper(ans,o,c-1,a+')');
        }
        return ans;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        return helper(ans,n,n,"");
        
    }
};