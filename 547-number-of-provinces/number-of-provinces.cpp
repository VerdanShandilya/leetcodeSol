class Solution {
public:
    void bfs(vector<vector<int>> &g , vector<bool> &vis ,int node){
        vis[node]=true;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(int i=0;i<g[temp].size();i++){
                if(!vis[g[temp][i]]){
                    vis[g[temp][i]]=true;
                    q.push(g[temp][i]);
                }
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> g(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                int u=isConnected[i][j];
                if(i!=j && u==1){
                    g[i].push_back(j);
                }
            }
        }
        vector<bool> vis(isConnected.size(),false);
        int ans=0;
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                ans++;
                bfs(g,vis,i);
            }
        }
        return ans;
    }
};