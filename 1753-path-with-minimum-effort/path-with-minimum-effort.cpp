class Solution {
public:
        int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int m =heights.size(), n =heights[0].size();
        vector<vector<int>> ans(m,vector<int>(n,INT_MAX));
        ans[0][0]=0;
        pq.push({0,{0,0}});
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int weight=temp.first;
            int row=temp.second.first;
            int col=temp.second.second;
            if (row==m-1 && col==n-1) {
                return weight;
            }
            for(auto& temp2 : dir) {
                int nrow=temp2.first + row;
                int ncol=temp2.second + col;
                if (nrow>=0 && ncol>=0 && nrow<m && ncol<n) {
                    int newEffort = max(weight, abs(heights[row][col] - heights[nrow][ncol]));
                    if (ans[nrow][ncol]>newEffort) {
                        ans[nrow][ncol]=newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }       
};