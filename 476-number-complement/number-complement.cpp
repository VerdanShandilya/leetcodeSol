class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        long i=0;
        while(num){
            int a=num&1;
            if(a==0){
                ans+=pow(2,i);
            }
            i++;
            num>>=1;
        }
        return ans;
    }
};