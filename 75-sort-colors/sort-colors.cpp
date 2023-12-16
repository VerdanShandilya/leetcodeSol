class Solution {
public:
    void sortColors(vector<int>& nums) {
         int i, key, j;
    for (i = 1; i < nums.size(); i++) {
        key = nums[i];
        j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }
    return;
    }
};