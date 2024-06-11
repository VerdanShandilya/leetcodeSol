class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count=0;
        long long ans=0;
        for(int i=0;i<=31;i++){
            count=0;
            for(int j=0;j<nums.size();j++){
                if((nums[j] & (1<<i))){
                    count++;
                }
            }
            if(count%3==0){
                ans+=0*pow(2,i);
            }
            else{
                ans+=1*pow(2,i);
            }
        }
        return int(ans);
    }
};