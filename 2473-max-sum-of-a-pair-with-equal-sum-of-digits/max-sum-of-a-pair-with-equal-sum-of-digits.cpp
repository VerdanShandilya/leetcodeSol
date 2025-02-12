class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            int num=nums[i];
            while(num){
                int r=num%10;
                sum+=r;
                num/=10;
            }
            if(m.find(sum)!=m.end()){
                ans=max(ans,m[sum]+nums[i]);
            }
            m[sum]=max(m[sum],nums[i]);
        }
        return ans;
    }
};