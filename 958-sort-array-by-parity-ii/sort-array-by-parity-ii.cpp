class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int left=0;
        int right=1;
        while(right<nums.size() && left<nums.size()){
            if(nums[left]%2==0){
                left+=2;
            }
            else if(nums[right]%2!=0){
                right+=2;
            }
            else{
                swap(nums[left],nums[right]);
                left+=2;
                right+=2;
            }
        }
        return nums;
    }
};