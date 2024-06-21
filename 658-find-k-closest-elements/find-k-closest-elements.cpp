class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> v;
        priority_queue<pair<int,int>> q;
        for(int i=0;i<arr.size();i++){
            q.push({abs(arr[i]-x),arr[i]});
            if(q.size()>k){
                q.pop();
            }
        }
        while(!q.empty()){
            pair<int,int> p=q.top();
            v.push_back(p.second);
            q.pop();
        }
        sort(v.begin(),v.end());
        return v;
    }
};