class Solution {
public:
    void helper(int n,vector<string> &s,string ans){
        if(n==0){
            s.push_back(ans);
            return;
        }
        if(ans.size()==0){
            helper(n-1,s,ans+'a');
            helper(n-1,s,ans+'b');
            helper(n-1,s,ans+'c');
        }
        else if(ans[ans.size()-1]=='a'){
            helper(n-1,s,ans+'b');
            helper(n-1,s,ans+'c');
        }
        else if(ans[ans.size()-1]=='b'){
            helper(n-1,s,ans+'a');
            helper(n-1,s,ans+'c');
        }
        else if(ans[ans.size()-1]=='c'){
            helper(n-1,s,ans+'a');
            helper(n-1,s,ans+'b');
        }

    }
    string getHappyString(int n, int k) {
        vector<string> s;
        string ans="";
        helper(n,s,ans);
        if(k>s.size()){
            return "";
        }
        return s[k-1];
    }
};