class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a=0;
        for(int i=0;i<nums.size();i++){
            a=a^nums[i];
        }
        int mask=1;
        for(int i=0;i<=31;i++){
            if((a & mask)==0){
                mask=mask << 1;
            }
            else break;
        }
        int xor1=0;
        int xor2=0;
        for(int i=0;i<nums.size();i++)
        if(nums[i] & mask){
            xor1=xor1^nums[i];
        }
        else{
            xor2=xor2^nums[i];
        }
        return {xor1,xor2};
    }
};