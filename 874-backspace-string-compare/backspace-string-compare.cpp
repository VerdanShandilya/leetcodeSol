class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a;
        for(int i=0;i<s.size();i++){
            if(!a.empty() && s[i]=='#'){
                a.pop();
            }
            else if(s[i]!='#'){
                a.push(s[i]);
            }
        }
        string ans1="";
        while(!a.empty()){
            ans1+=a.top();
            a.pop();
        }
        for(int i=0;i<t.size();i++){
            if(!a.empty() && t[i]=='#'){
                a.pop();
            }
            else if(t[i]!='#'){
                a.push(t[i]);
            }
        }
        string ans2="";
        while(!a.empty()){
            ans2+=a.top();
            a.pop();
        }
        return ans1==ans2;
    }
};