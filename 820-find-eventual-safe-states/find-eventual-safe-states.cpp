class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<bool> &vis,vector<bool> &dfsvis,vector<bool> &ansb,int node){
        vis[node]=true;
        dfsvis[node]=true;
        for(int i=0;i<graph[node].size();i++){
            if(!vis[graph[node][i]]){
                dfs(graph,vis,dfsvis,ansb,graph[node][i]);
            }
            if(dfsvis[graph[node][i]]) {
                ansb[node] = true;
            }
            if (ansb[graph[node][i]]) {
                ansb[node] = true;
            }
        }
        dfsvis[node]=false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size(),false);
        vector<bool> dfsvis(graph.size(),false);
        vector<bool> ansb(graph.size(),false);
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
                dfs(graph,vis,dfsvis,ansb,i);
            }
        }
        vector<int> ans;
        for(int i=0;i<ansb.size();i++){
            if(ansb[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};