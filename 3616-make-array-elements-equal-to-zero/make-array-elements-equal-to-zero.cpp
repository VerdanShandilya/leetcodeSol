class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int lsum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            lsum+=nums[i];
            if(nums[i]==0){
                int rsum=0;
                for(int j=i+1;j<nums.size();j++){
                    rsum+=nums[j];
                }
                if(abs(rsum-lsum)==0){
                    ans=ans+2;
                }
                else if(abs(lsum-rsum)==1){
                    ans=ans+1;
                }
            }
        }
        return ans;
    }
};