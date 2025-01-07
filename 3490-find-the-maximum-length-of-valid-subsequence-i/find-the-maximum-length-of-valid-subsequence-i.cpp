class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int o=0;
        int e=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                e++;
            }
            else{
                o++;
            }
        }
        int ans=max(o,e);
        int count=1;
        int l=0;
        int r=1;
        while(r<nums.size()){
            if((nums[l]+nums[r])%2!=0){
                l=r;
                count++;
            }
            r++;   
        }
        return max(ans,count);
    }
};