class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        vector<int> v(26,0);
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                v[s[i]-'a']++;
                if(v[s[i]-'a']<=1)
                ans+=s[i];
            }
            else{
                if(i>0)
                v[s[i-1]-'a']=0;
                ans+=s[i];
            }
        }
        return ans+s[s.size()-1];
    }
};