class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int totalops=nums.size()+maxOperations;
        int ans=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            long long count = 0;
            for(int i=0;i<nums.size();i++){
                count+=ceil(nums[i]/(double)mid)-1;
            }
            if(count<=maxOperations){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};