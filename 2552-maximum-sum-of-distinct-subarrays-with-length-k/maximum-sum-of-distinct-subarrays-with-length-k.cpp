class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        long ans=0;
        long sum=0;
        unordered_map<int,int> m;
        while(r<nums.size()){
            m[nums[r]]++;
            sum+=nums[r];
            while(m[nums[r]]>1){
                if(m.find(nums[l])!=m.end()){
                    m[nums[l]]--;
                    sum=sum-nums[l];
                }
                l++;
            }
            if(r-l+1==k){
                ans=max(ans,sum);
                if(m.find(nums[l])!=m.end()){
                    m[nums[l]]--;
                    sum=sum-nums[l];
                }
                r++;
                l++;
            }
            else{
                r++;
            }
        }
        return ans;
    }
};