
class Solution {
public:
    long long helper(vector<int>& nums, int val) {
        long long count = 0;
        int n = nums.size();
        int j = n - 1;
        for (int i = 0; i < j; ++i) {
            while (i < j && nums[i] + nums[j] > val)
                --j;
            count += j - i;
        }
        return count;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return helper(nums, upper) - helper(nums, lower - 1);
    }
};