class Solution {
public:
    int helper(int num){
        int ans=0;
        while(num){
            int r=num%10;
            ans=ans+pow(r,2);
            num=num/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_map<int,int> m;
        int ans=0;
        while(true){
            ans=helper(n);
            n=ans;
            if(ans==1){
                return true;
            }
            if(m[ans]==2){
                return false;
            }
            m[ans]++;
        } 
        return true;
    }
};