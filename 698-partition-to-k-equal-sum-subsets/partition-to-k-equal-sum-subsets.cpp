class Solution {
public:
    bool ans=false;
    void helper(vector<int> &v,vector<int>& nums,int index,int sum){
        if(index==nums.size()){
            bool a=true;
            for(int i=1;i<v.size();i++){
                if(v[i]!=v[i-1]){
                    a=false;
                }
            }
            if(a){
                ans=true;
            }
            return;
        }
        if(ans==true){
            return;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]+nums[index]>sum) continue;
            v[i]+=nums[index];
            helper(v,nums,index+1,sum);
            v[i]-=nums[index];
            if(v[i]==0){
                break;
            }
        }
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0){
            return false;
        }
        sort(nums.rbegin(), nums.rend());
        vector<int> v(k,0);
        helper(v,nums,0,sum/k);
        return ans;
    }
};