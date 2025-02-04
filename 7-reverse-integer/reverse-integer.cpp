class Solution {
public:
    int reverse(int x) {
        long rev=0;
        while(x){
            int rem=x%10;
            rev=(rev*10)+(rem);
            x=x/10;
        }
        if(rev>INT_MAX || rev<INT_MIN)
        return 0;
        return rev;
    }
};