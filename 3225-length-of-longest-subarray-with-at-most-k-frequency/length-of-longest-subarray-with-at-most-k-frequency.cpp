class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int count=0;
        int ma=0;
        int prev=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            while(m[nums[i]]>k){
                ma=max(ma,count);
                m[nums[prev]]--;
                count--;
                prev++;
            }
            count++;
        }
        return max(count,ma);
    }
};