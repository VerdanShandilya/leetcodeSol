class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        int prod=1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            product*=nums[i];
            if(nums[i]==0){
                count++;
                continue;
            }
            else{
                prod*=nums[i];
            }
        }
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0 && count==1){
                v.push_back(prod);
            }
            else if(nums[i]==0){
                v.push_back(0);
            }
            else{
                v.push_back(product/nums[i]);
            }
        }
        return v;
    }
};