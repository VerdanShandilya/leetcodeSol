class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num=0;
        for(int i=0;i<nums.size();i++){
            num=num^nums[i];
        }
        int count=0;
        while(num){
            if(num & (1<<count)){
                break;
            }
            count++;
        }
        int bin1=0;
        int bin2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] & (1<<count)){
                bin1=bin1^nums[i];
            }
            else{
                bin2=bin2^nums[i];
            }
        }
        return {bin1,bin2};
    }
};