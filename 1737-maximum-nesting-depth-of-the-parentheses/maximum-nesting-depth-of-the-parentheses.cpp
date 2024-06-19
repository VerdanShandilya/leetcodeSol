class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int count=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
                count++;
            }
            else if(s[i]==')'){
                st.pop();
                count--;
            }
            ans=max(count,ans);
        }
        return ans;
    }
};