class Solution {
public:
    bool checkValidString(string s) {
        stack<char> v;
        stack<char> vv;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                v.push(i);
            }
            else if(s[i]=='*'){
                vv.push(i);
            }
            else{
                if(!v.empty())
                    v.pop();
                else if(!vv.empty())
                    vv.pop();
                else
                    return false;
            }
        }
        while(!v.empty() && !vv.empty() && v.top()<vv.top()){
            v.pop();
            vv.pop();
        }
        if(v.empty()){
            return true;
        }
        return false;
    }
};
