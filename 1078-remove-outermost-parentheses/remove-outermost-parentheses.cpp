class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(st.empty() && st.size()==0){
                st.push(s[i]);
            }
            else if(s[i]=='(' && st.size()>=1){
                st.push(s[i]);
                ans+="(";
            }
            else if(s[i]==')' && st.size()>1){
                ans+=")";
                st.pop();
            }
            else{
                st.pop();
            }
        }
        return ans;
    }
};