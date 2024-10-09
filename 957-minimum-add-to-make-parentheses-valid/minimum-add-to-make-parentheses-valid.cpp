class Solution {
public:
    int minAddToMakeValid(string a) {
        stack<char> s;
        for(int i=0;i<a.size();i++){
            if(s.empty()){
                s.push(a[i]);
            }
            else if(a[i]=='('){
                s.push(a[i]);
            }
            else if(a[i]==')' && s.top()=='('){
                s.pop();
            }
            else{
                s.push(a[i]);
            }
        }
        return s.size();
    }
};