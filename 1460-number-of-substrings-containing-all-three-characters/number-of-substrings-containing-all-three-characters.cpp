class Solution {
public:
    int helper(string s,int k){
        int l=0;
        int r=0;
        int uniq=0;
        int ans=0;
        unordered_map<char,int> m;
        while(r<s.size()){
            m[s[r]]++;
            if(m[s[r]]==1){
                uniq++;
            }
            while(uniq>k){
                m[s[l]]--;
                if(m[s[l]]==0){
                    uniq--;
                }
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubstrings(string s) {
        return helper(s,3)-helper(s,2);
    }
};