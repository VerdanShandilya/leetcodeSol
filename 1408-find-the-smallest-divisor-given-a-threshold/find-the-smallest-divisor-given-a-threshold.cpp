class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int i=1;
        int j=nums[nums.size()-1];
        int ans=INT_MAX;
        while(i<=j){
            int mid=(i+j)/2;
            int sum=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]%mid==0){
                    sum+=nums[i]/mid;
                }
                else{
                    sum+=(nums[i]/mid)+1;
                }
            }
            if(sum>threshold){
                i=mid+1;
            }
            else{
                ans=mid;
                j=mid-1;
            }
        }
        return ans;
    }
};