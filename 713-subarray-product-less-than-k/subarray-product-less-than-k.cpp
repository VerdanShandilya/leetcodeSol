class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        int p=1;
        for(int i=0;i<nums.size();i++){
            p=1;
            for(int j=i;j<nums.size();j++){
                p*=nums[j];
                if(p<k){
                    count++;
                }
                else{
                    break;
                }
            }
        }
        return count;
    }
};