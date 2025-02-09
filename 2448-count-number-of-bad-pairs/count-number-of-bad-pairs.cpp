class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long tpairs=(long long)n*(n-1)/2;
        unordered_map<int,long long> m;
        for (int i = 0; i < n; i++) {
            int diff = nums[i] - i;
            tpairs-=m[diff];
            m[diff]++;
        }
        return tpairs;
    }
};