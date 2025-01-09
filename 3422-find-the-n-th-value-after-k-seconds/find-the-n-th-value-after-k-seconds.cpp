class Solution {
public:
    const int mod=1e9+7;
    int valueAfterKSeconds(int n, int k) {
        vector<long long> v(n,1);
        for(int i=0;i<k;i++){
            for(int j=1;j<v.size();j++){
                v[j]=v[j-1]+v[j]%mod;
            }
        }
        return v[v.size()-1]%mod;
    }
};