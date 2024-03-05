#include <bits/stdc++.h>
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int c=0;
        int lop=0;
        for(int i=0;i<nums.size()/2;i++){
            c=c+min(nums[lop],nums[lop+1]);
            lop=lop+2;
        }
        return c;
    }
};