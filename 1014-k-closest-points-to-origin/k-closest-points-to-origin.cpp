class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> q;
        int  dist=0;
        for(int i=0;i<points.size();i++){
            dist=pow((points[i][0]-0),2) + pow((points[i][1]-0),2);
            q.push({dist,i});
            if(q.size()>k){
                q.pop();
            }
        }
        vector<vector<int>> ans;
        while(!q.empty()){
            pair<int,int> p=q.top();
            q.pop();
            ans.push_back(points[p.second]);
        }
        return ans;
    }
};