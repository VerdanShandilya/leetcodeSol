class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(abs(nums[j]-nums[i])>k){
                ans++;
                j=i;
                i--;
            }
        }
        return ans+1;
    }
};