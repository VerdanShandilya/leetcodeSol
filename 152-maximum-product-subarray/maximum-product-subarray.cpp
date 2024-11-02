class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m=INT_MIN;
        int p=1;
        for(int i=0;i<nums.size();i++){
          p*=nums[i];
          m=max(p,m);
          if(p==0)
           p=1;
        }
        p=1;
        for(int i=nums.size()-1;i>=0;i--){
          p*=nums[i];
          m=max(p,m);
          if(p==0)
           p=1;
        }
        return m;
    }
};