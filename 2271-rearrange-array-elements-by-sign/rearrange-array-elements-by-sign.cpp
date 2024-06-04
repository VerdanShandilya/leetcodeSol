class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v(nums.size(),0);
        int i=0;
        int j=1;
        for(int z=0;z<nums.size();z++){
            if(nums[z]>0){
                v[i]=nums[z];
                i+=2;
            }
            else{
                v[j]=nums[z];
                j+=2;
            }
        }
        return v;
    }
};