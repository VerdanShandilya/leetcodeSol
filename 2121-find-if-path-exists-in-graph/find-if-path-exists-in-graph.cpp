class Solution {
public:
    bool bfs(vector<vector<int>> &g,int n,int source, int destination){
        vector<bool> visited(n,false);
        queue<int> q;
        visited[source]=true;
        q.push(source);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            if(temp==destination){
                return true;
            }
            for(int i=0;i<g[temp].size();i++){
                if(!visited[g[temp][i]]){
                    visited[g[temp][i]]=true;
                    q.push(g[temp][i]);
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> g(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        return bfs(g,n,source,destination);
    }
};