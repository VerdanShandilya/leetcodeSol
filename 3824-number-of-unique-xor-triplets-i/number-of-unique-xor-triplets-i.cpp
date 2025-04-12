class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        if(nums.size()==2){
            return 2;
        }
        int n=nums.size();
        int count=0;
        while(n>0){
            n=n>>1;
            count++;
        }
        return pow(2,count);
    }
};