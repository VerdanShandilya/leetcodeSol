class Solution {
public:
    string makeGood(string s) {
        stack<char> v;
        string ans="";
        for(int i=s.size()-1;i>=0;i--){
            if(v.size()==0){
                v.push(s[i]);
            }
            else if(abs(int(s[i])-int(v.top()))==32){
                v.pop();
            }
            else{
                v.push(s[i]);
            }
        }
        while(!v.empty()){
            ans+=v.top();
            v.pop();
        }
        return ans;
    }
};