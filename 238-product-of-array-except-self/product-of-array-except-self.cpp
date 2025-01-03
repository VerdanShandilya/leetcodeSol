class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int a=0;
        int p=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)
            p*=nums[i];
            else
            a++;
        }
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(a==1 && nums[i]==0){
                ans[i]=p;
            }
            else if(a==0){
                ans[i]=p/nums[i];
            }
            else{
                ans[i]=0;
            }
        }
        return ans;
    }
};