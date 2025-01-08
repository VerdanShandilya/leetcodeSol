class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int lim = (int)(sqrt(r));
        vector<bool> v(lim + 1, true);
        v[0] = v[1] = false; 
        for(int i = 2;i * i<=lim;i++) {
            if(v[i]) {
                for (int j = i * i; j <= lim; j += i) {
                    v[j] = false;
                }
            }
        }
        int ans=0;
        for(int i=2;i<=lim;i++){
            if(v[i]){
                int z=i*i;
                if(z>=l && z<=r){
                    ans++;
                }
            }
        }
        return r-l+1-ans;
    }
};