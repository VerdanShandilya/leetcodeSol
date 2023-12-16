class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v;
        int z=0;
        int x=1;
        int c=2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==z){
                v.push_back(z);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                v.push_back(x);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==c){
                v.push_back(c);
            }
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=v[i];
        }
        return;
    }
};