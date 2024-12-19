class Solution {
public:
    int helper(string s){
        unordered_map<char,int> m;
        int l=0;
        int r=0;
        int ans=0;
        int uni=0;
        while(r<s.size()){
            m[s[r]]++;
            if(m[s[r]]==1){
                uni++;
            }
            if(uni==3){
                while(uni==3){
                    ans+=(s.size()-r);
                    m[s[l]]--;
                    if(m[s[l]]==0){
                        uni--;
                    }
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
    int numberOfSubstrings(string s) {
        return helper(s);
    }
};