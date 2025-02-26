class Solution {
public:
    void helperpacific(vector<vector<int>>& heights,queue<pair<int,int>> &q,vector<vector<bool>> &pacific){
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        vector<pair<int,int>> dir= {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()){
            auto temp = q.front();
            int row = temp.first;
            int col = temp.second;
            q.pop();
            vis[row][col]=true;
            pacific[row][col]=true;
            for(auto i : dir){
                int nrow = row+i.first;
                int ncol = col+i.second;
                if(nrow>-1 && ncol>-1 && nrow<n && ncol<m && !vis[nrow][ncol] && heights[nrow][ncol]>=heights[row][col]){
                    q.push({nrow,ncol});
                }
            }
        }
    }
     void helperatlantic(vector<vector<int>>& heights,queue<pair<int,int>> &q1,vector<vector<bool>> &atlantic){
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        vector<pair<int,int>> dir= {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q1.empty()){
            auto temp = q1.front();
            int row = temp.first;
            int col = temp.second;
            q1.pop();
            vis[row][col]=true;
            atlantic[row][col]=true;
            for(auto i : dir){
                int nrow = row+i.first;
                int ncol = col+i.second;
                if(nrow>-1 && ncol>-1 && nrow<n && ncol<m && !vis[nrow][ncol] && heights[nrow][ncol]>=heights[row][col]){
                    q1.push({nrow,ncol});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        queue<pair<int,int>> q;
        queue<pair<int,int>> q1;
        vector<vector<bool>> pacific(n , vector<bool> (m,false));
        vector<vector<bool>> atlantic(n , vector<bool> (m,false));
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(i==0 || j==0){
                    q.push({i,j});
                    pacific[i][j]=true;
                }
                if(i==n-1 || j==m-1){
                    q1.push({i,j});
                    atlantic[i][j]=true;
                }
            }
        }
        helperpacific(heights,q,pacific);
        helperatlantic(heights,q1,atlantic);
        vector<vector<int>> ans;
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(pacific[i][j]==true && atlantic[i][j]==true){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};