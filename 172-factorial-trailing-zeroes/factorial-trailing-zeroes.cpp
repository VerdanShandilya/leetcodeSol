class Solution {
public:
    int trailingZeroes(int n) {
        int a=5;
        int ans=0;
        while(a<=n){
            ans+=n/a;
            a=a*5;
        }
        return ans;
    }
};