class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size()==1) {
            return 1;
        }
        int ans=0;
        for(int i=0;i<points.size();i++){
            unordered_map<float,int> m;
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<points.size();j++){
                int x2=points[j][0];
                int y2=points[j][1];
                float slope=0;
                if(x2==x1){
                    slope=FLT_MAX;

                }
                else{
                    slope=(float)(y2-y1)/(x2-x1);
                }
                m[slope]++;
                ans=max(ans,m[slope]);
            }
        }
        return ans+1;
    }
};