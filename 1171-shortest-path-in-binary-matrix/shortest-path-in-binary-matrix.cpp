class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0){
            return -1;
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        vector<vector<int>> ans(grid.size(),vector<int>(grid.size(),INT_MAX));
        ans[0][0]=1;
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,-1},{1,-1},{-1,1}};
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int wt=temp.first;
            int row=temp.second.first;
            int col=temp.second.second;
            for(auto i : dir){
                int nrow=row+i.first;
                int ncol=col+i.second;
                if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid.size() && grid[nrow][ncol]==0){
                    if(ans[nrow][ncol]>ans[row][col]+1){
                        ans[nrow][ncol]=ans[row][col]+1;
                        q.push({ans[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        if(ans[grid.size()-1][grid.size()-1]==INT_MAX){
            return -1;
        }
        return ans[grid.size()-1][grid.size()-1];
    }
};