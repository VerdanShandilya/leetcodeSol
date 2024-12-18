class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int count=0;
        int ans=0;
        while(r<nums.size()){
            if(nums[r]%2!=0){
                k--;
                count=0;
            }
            while(k==0){
                count++;
                if(nums[l]%2!=0){
                    k++;
                }
                l++;
            }
            ans+=count;
            r++;
        }
        return ans;
    }
};