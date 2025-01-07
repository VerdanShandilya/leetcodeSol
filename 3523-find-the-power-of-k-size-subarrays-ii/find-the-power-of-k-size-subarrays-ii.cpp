class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int l=1;
        int r=k;
        vector<int> ans(nums.size()-k+1,-1);
        int count=1;
        for(int i=1;i<k;i++){
            if(nums[i]-1!=nums[i-1]){
                count=1;
            }
            else{
                count++;
            }
        }
        if(count==k)
        ans[0]=nums[k-1];
        while(r<nums.size()){
            if(nums[r]-1!=nums[r-1]){
                count=1;
            }
            else{
                count++;
            }
            if(count>=k){
                ans[l]=nums[r];
            }
            l++;r++;
        }
        return ans;
    }
};