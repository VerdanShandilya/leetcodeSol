class Solution {
public:
    int helper(string s,int size){
        int l=0;
        int r=0;
        unordered_map<int,int> m;
        int ans=0;
        while(r<s.size()){
            m[s[r]]++;
            while(m.size()>size){
                m[s[l]]--;
                if(m[s[l]]==0){
                    m.erase(s[l]);
                }
                l++;
            }
            ans+=(r-l)+1;
            r++;
        }
        return ans;
    }
    int numberOfSubstrings(string s) {
        return helper(s,3)-helper(s,2);
    }
};