class Solution {
public:
    long long minimumSteps(string s) {
        long c0=0;
        long ans=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                c0++;
            }
            if(s[i]=='1'){
                ans+=c0;
            }
        }
        return ans;
    }
};