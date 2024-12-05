class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int r=0;
        int sum=0;
        int ans=0;
        unordered_map<int,int> m;
        m[0] = 1;
        while(r<nums.size()){
            sum+=nums[r];
            if(m.find(sum-k)!=m.end()){
                ans=ans+m[sum-k];
            }
            m[sum]+=1;
            r++;
        }
        return ans;
    }
};