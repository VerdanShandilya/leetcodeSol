class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size() && nums[i]<0 && k!=0){
            nums[i]=abs(nums[i]);
            ++i;
            --k;
        }
        sort(nums.begin(),nums.end());
        k=k%2;
        if(k==1){
            nums[0]=-nums[0];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];
        }
        return ans;
    }
};
