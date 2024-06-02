class Solution {
public:
    int numberOfSteps(int num) {
        if(num==0){
            return 0;
        }
        int count=0;
        while(num!=0){
            if(num%2!=0){
                num=num-1;
                count++;
            }
            num=num/2;
            count++;
        }
    
        return count-1;
    }
};