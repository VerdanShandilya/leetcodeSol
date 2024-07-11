class Solution {
public:
    string reverseParentheses(string a) {
        stack<char> s;
        string ans1="";
        int count=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=')'){
                if(a[i]=='('){
                    count++;
                }
                if(count==0){
                    ans1+=a[i];
                }
                else{
                    s.push(a[i]);
                }
            }
            else{
                string ans="";
                while(s.top()!='('){
                    ans+=s.top();
                    s.pop();
                }
                count--;
                s.pop();
                if(count!=0){
                    for(int i=0;i<ans.size();i++){
                        s.push(ans[i]);
                    }
                }
                else{
                    ans1+=ans;
                }
            }
        }
        return ans1;
    }
};