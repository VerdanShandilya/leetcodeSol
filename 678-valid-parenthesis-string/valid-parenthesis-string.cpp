class Solution {
public:
    bool checkValidString(string a) {
        stack<char> s;
        stack<int> s1;
        for(int i=0;i<a.size();i++){
            if(a[i]=='('){
                s.push(i);
            }
            else if(a[i]=='*'){
                s1.push(i);
            }
            else{
                if(!s.empty()){
                    s.pop();
                }
                else if(!s1.empty()){
                    s1.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!s.empty() && !s1.empty() && s.top()<s1.top()){
            s.pop();
            s1.pop();
        }
        return s.empty();
    }
};