class Solution {
public:
    int ans=0;
    void helper(vector<int>& nums,int index,vector<int> &v){
        if(index>=nums.size()){
            int x=0;
            for(int i=0;i<v.size();i++){
                x^=v[i];
            }
            ans+=x;
            return;
        }
        v.push_back(nums[index]);
        helper(nums,index+1,v);
        v.pop_back();
        helper(nums,index+1,v);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> v;
        helper(nums,0,v);
        return ans;
    }
};