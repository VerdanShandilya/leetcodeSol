class Solution {
public:
    string makeGood(string s) {
        string ans="";
        stack<char> st;
        for(int i=s.size()-1;i>=0;i--){
            if(st.size()==0){
                st.push(s[i]);
            }
            else if(abs(int(s[i])-int(st.top()))==32){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};