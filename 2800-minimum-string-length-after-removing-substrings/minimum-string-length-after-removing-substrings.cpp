class Solution {
public:
    int minLength(string a) {
        stack<char> s;
        int i=0;
        while(i<a.size()){
            if(!s.empty() && a[i]=='B' && s.top()=='A'){
                s.pop();
            }
            else if(!s.empty() && a[i]=='D' && s.top()=='C'){
                s.pop();
            }
            else{
                s.push(a[i]);
            }
            i++;
        }
        return s.size();
    }
};