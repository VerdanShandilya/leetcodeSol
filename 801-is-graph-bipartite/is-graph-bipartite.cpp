class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int> &c,vector<bool> &vis,int n){
        queue<pair<int,int>> q;
        q.push({n,0});
        vis[n]=true;
        c[n]=0;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int node=temp.first;
            int color=temp.second;
            for(int i=0;i<graph[node].size();i++){
                if(!vis[graph[node][i]]){
                    q.push({graph[node][i],!color});
                    vis[graph[node][i]]=true;
                    c[graph[node][i]]=!color;
                }
                else{
                    if(c[graph[node][i]]==color){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size(),false);
        vector<int> c(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
                if(!bfs(graph,c,vis,i)){
                    return false;
                }
            }
        }
        return true;
    }
};