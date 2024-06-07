class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int l=1;
        int h=nums[nums.size()-1];
        int ans=INT_MAX;
        while(l<=h){
            int mid=(h+l)/2;
            int sum=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]%mid==0){
                    sum+=nums[i]/mid;
                }
                else{
                    sum+=(nums[i]/mid)+1;
                }
            }
            if(sum<=threshold){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};