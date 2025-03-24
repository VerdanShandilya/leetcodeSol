class Solution {
public:
    void helper(vector<int>& nums,vector<int> &v,set<vector<int>> &s,int index){
        if(index>=nums.size()){
            s.insert(v);
            return;
        }
        for(int i=0;i<=v.size();i++){
            v.insert(v.begin()+i,nums[index]);
            helper(nums,v,s,index+1);
            v.erase(v.begin()+i);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> v;
        helper(nums,v,s,0);
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};