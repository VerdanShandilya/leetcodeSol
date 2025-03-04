class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n>0){
            if(n%3!=1 && n%3!=0){
                return false;
            }
            n=n/3;
        }
        return true;
    }
};