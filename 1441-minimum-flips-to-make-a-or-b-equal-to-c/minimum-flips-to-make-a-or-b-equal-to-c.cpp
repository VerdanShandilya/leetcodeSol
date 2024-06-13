class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        int n=c;
        int l=max(log2(a),log2(b));
        int f=int(max(l,int(log2(c))));
        for(int i=0;i<=f;i++){
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