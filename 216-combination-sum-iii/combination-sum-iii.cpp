class Solution {
public:
    void helper(int k,int &n,vector<vector<int>> &ans,vector<int> &v,int index,int sum,vector<int> &temp){
        if(k==0){
            if(sum==n){
                ans.push_back(v);
            }
            return;
        }
        if(index>=temp.size() || k<0){
            return;
        }
        v.push_back(temp[index]);
        helper(k-1,n,ans,v,index+1,sum+temp[index],temp);
        v.pop_back();
        helper(k,n,ans,v,index+1,sum,temp);
    }
    vector<vector<int>> combinationSum3(int k, int n){
        vector<int> temp;
        for(int i=1;i<=9;i++){
            temp.push_back(i);
        }
        vector<vector<int>> ans;
        vector<int> v;
        helper(k,n,ans,v,0,0,temp);
        return ans;
    }
};
