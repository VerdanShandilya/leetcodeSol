class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int mi=0;
        int ma=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                mi++;
            }
            else if(nums[i]>0){
                ma++;
            }
        }
        return max(ma,mi);
    }
};