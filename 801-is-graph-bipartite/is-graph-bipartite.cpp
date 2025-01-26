class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int> &color,vector<bool> &vis,int node){
        queue<pair<int,int>> q;
        color[node]=0;
        q.push({node,0});
        while(!q.empty()){
            int temp=q.front().first;
            int col=q.front().second;
            q.pop();
            vis[temp]=true;
            for(int i=0;i<graph[temp].size();i++){
                if(!vis[graph[temp][i]]){
                    color[graph[temp][i]]=!col;
                    q.push({graph[temp][i],!col});
                }
                else if(color[graph[temp][i]]==color[temp]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size(),false);
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
                if(!bfs(graph,color,vis,i)){
                    return false;
                }
            }
        }
        return true;
    }
};