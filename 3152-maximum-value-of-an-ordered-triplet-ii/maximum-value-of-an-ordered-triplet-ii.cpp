class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();

        vector<int> prefix(n),suffix(n);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            prefix[i]=max(nums[i],prefix[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(nums[i],suffix[i+1]);
        }
        for(int j=1;j<n-1;j++){
            long long curr=1LL*(prefix[j-1]-nums[j])*suffix[j+1];
            res=max(res,curr);
        }
        return res;
    }
};