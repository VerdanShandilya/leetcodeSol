class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> v(nums.size(),0);
        vector<bool> ans(queries.size(),false);
        int count=1;
        v[0]=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]%2!=nums[i]%2){
                count++;
            }
            else{
                count=1;
            }
            v[i]=count;
        }
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0];
            int end=queries[i][1];
            int diff=end-start;
            if(diff+1<=v[end]){
                ans[i]=true;
            }
            else{
                ans[i]=false;
            }
        }
        return ans;
    }
};