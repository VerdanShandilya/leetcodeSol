class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            vector<int> v(26,0);
            for(int j=i;j<s.size();j++){
                v[s[j]-'a']++;
                bool a=true;
                for(int z=0;z<26;z++){
                    if(v[z]>0 && v[z]<k){
                        a=false;
                    }
                }
                if(a)
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};