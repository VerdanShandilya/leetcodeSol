class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        int n=c;
        while(a>0 || b>0 || c>0){
            int ma=a&1;
            int mb=b&1;
            int mc=c&1;
            if(mc==0){
                count+=(ma+mb);
            }
            else{
                if(ma==0 && mb==0){
                    count++;
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return count;
    }
};