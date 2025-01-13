class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int diff=0;
        for(auto i : m){
            if(i.second%2==0){
                diff+=2;
            }
            else{
                diff+=1;
            }
        }
        return diff;
    }
};