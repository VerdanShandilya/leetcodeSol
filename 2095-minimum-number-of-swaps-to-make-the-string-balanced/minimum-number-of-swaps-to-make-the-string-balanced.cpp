class Solution {
public:
    int minSwaps(string a) {
        stack<char> s;
        for(int i=0;i<a.size();i++){
            if(s.empty()){
                s.push(a[i]);
            }
            else if(a[i]==']' && s.top()=='['){
                s.pop();
            }
            else{
                s.push(a[i]);
            }
        }
        int sc=s.size()/2;
        if(sc%2==0){
            return sc/2;
        }
        return sc/2+1;
    }
};