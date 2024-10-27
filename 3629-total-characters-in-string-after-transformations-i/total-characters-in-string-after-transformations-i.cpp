class Solution {
public:
const int mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<long> v(26,0);
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']++;
        }
        for(int i=0;i<t;i++){
            vector<long> temp(26,0);
            for(int j=0;j<26;j++){
                if(j==25){
                    temp[0]=(temp[0]+v[25])%mod;
                    temp[1]=(temp[1]+v[25])%mod;
                }
                else{
                    temp[j+1]=(temp[j+1]+v[j])%mod;
                }
            }
            v=temp;
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans+=v[i];
            ans%=mod;
        }
        return ans;
    }
};