class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> q;
        for(int i=0;i<arr.size();i++){
            int diff=abs(x-arr[i]);
            q.push({diff,i});
            if(q.size()>k){
                q.pop();
            }
        }
        vector<int> ans;
        while(!q.empty()){
            auto temp=q.top();
            q.pop();
            ans.push_back(arr[temp.second]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};