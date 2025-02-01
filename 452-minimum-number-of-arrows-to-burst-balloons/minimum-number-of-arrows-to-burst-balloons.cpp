class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=1;
        for(int i=1;i<points.size();i++){
            if(points[i-1][1]>=points[i][0]){
                points[i][1]=min(points[i-1][1],points[i][1]);
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};