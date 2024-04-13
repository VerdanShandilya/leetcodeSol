class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        for(int i=0;i<nums.size()-2;i=i+3){
            vector<int> v1;
            v1.push_back(nums[i]);
            v1.push_back(nums[i+1]);
            v1.push_back(nums[i+2]);
            v.push_back(v1);
        }
        int j=0;
        vector<vector<int>>an;
        for(int i=0;i<v.size();i++){
            if((v[i][j+1]-v[i][j])>k || (v[i][j+2]-v[i][j+1])>k || (v[i][j+2]-v[i][j])>k){
                return an;
            }
        }
        return v;
    }
};