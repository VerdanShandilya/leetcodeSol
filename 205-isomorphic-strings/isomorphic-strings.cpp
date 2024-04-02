class Solution {
public:
    bool isIsomorphic(string s, string t) {
        for(int i=0;i<s.length();i++){
            for(int j=i+1;j<s.length();j++){
                if(s[j]==s[i] && t[j]!=t[i]){
                    return false;
                }
                if(s[j]!=s[i] && t[j]==t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};