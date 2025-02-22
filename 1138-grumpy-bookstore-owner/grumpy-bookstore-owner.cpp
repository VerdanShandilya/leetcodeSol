class Solution {
public:
    int maxSatisfied(vector<int>& nums, vector<int>& grumpy, int m) {
        int one=0;
        int zero=0;
        int ans=0;
        int l=0;
        int r=0;
        int sum=0;
        while(r<nums.size()){
            if(grumpy[r]==1){
                one++;
                sum+=nums[r];
            }
            if(r-l+1<m){
                r++;
                continue;
            }
            else if(r-l+1==m){
                if(one>0){
                    ans=max(ans,sum);
                }
                if(grumpy[l]==1){
                    sum-=nums[l];
                    one--;
                }
                l++;
                r++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(grumpy[i]==0){
                ans+=nums[i];
            }
        }
        return ans;
    }
};