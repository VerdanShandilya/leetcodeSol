class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int l=0;
        int r=0;
        int ans=0;
        while(r<s.size()){
            m[s[r]]++;
            while(m[s[r]]>1){
                if(m.find(s[l])!=m.end()){
                    m[s[l]]--;
                }
                l++;
            }
            r++;
            int count=0;
            for(auto i : m){
                if(i.second>0){
                    count++;
                }
            }
            ans=max(ans,count);
        }
        return ans;
    }
};