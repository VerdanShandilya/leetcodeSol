class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        vector<int> v(nums.size()+1,0);
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v1=queries[i][1];
            v[u]++;
            v[v1+1]--;
        }
        for(int i=1;i<nums.size();i++){
            v[i]=v[i]+v[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(v[i]<nums[i]){
                return false;
            }
        }
        return true;
    }
};