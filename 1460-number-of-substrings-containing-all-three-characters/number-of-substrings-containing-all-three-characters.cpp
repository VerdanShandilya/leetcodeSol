class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> m;
        m['a']=-1;
        m['b']=-1;
        m['c']=-1;
        int r=0;
        int ans=0;
        while(r<s.size()){
            m[s[r]]=r;
            int mi=min(m['a'],min(m['b'],m['c']));
            if(mi!=-1){
                ans+=(mi+1);
            }
            r++;
        }
        return ans;
    }
};