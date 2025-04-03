class Solution {
public:
    bool helper(vector<int>& arr,int index,vector<bool> &vis){
        if(index>=arr.size() || vis[index]){
            return false;
        }
        vis[index]=true;
        if(arr[index]==0){
            return true;
        }
        bool a = helper(arr,index+arr[index],vis);
        bool b = helper(arr,index-arr[index],vis);
        return a || b;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(),false);
        return helper(arr,start,vis);
    }
};