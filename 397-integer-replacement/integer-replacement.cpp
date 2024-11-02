class Solution {
public:
    int helper(long n){
        if(n<1){
            return INT_MAX;
        }
        if(n==1){
            return 0;
        }
        int a=INT_MAX;
        int b=INT_MAX;
        int c=INT_MAX;
        if(n%2==0){
            a=1+helper(n/2);
        }
        else{
            b=1+helper(n+1);
            c=1+helper(n-1);
        }
        return min({a,b,c});
    }
    int integerReplacement(int n) {
        return helper(n);
    }
};