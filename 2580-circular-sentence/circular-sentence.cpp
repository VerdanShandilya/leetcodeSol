class Solution {
public:
    bool isCircularSentence(string s) {
        for(int i=1;i<s.size()-1;i++){
            if(s[i]==' '){
                if(s[i-1]!=s[i+1]){
                    return false;
                }
            }
        }
        return s[0]==s[s.size()-1];
    }
};