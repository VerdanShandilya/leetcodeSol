class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        vector<vector<int>> ans(n, vector<int> (m,INT_MAX));
        ans[0][0]=0;
        q.push({0,{0,0}});
        vector<pair<int,int>> dir={{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()){
            int row=q.top().second.first;
            int col=q.top().second.second;
            int effort=q.top().first;
            q.pop();

            for(auto i : dir){
                int nrow=row+i.first;
                int ncol=col+i.second;
                if(nrow>-1 && ncol>-1 && nrow<n && ncol<m){
                    int w=max(abs(heights[row][col]-heights[nrow][ncol]),effort);
                    if(ans[nrow][ncol]>w){
                        ans[nrow][ncol]=w;
                        q.push({ans[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return ans[n-1][m-1];
    }
};