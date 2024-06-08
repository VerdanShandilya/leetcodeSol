class Solution {
public:
    int helper(int num, int ans){
        if(num==0){
            return ans;
        }
        if(num%2==0){
        return helper(num/2,ans+1);
        }
        
            return helper(num-1,ans+1);
    }
    int numberOfSteps(int num) {
        return helper(num,0);
    }
};