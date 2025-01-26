class Solution {
public:
    bool dfs(vector<vector<int>> &g,vector<bool> &vis,vector<bool> &visdfs,int node){
        vis[node]=true;
        visdfs[node]=true;
        for(int i=0;i<g[node].size();i++){
            if(!vis[g[node][i]]){
                if(dfs(g,vis,visdfs,g[node][i])){
                    return true;
                }
            }
            else if(visdfs[g[node][i]]){
                return true;
            }
        }
        visdfs[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> g(numCourses);
        for(int i=0;i<pre.size();i++){
            int u=pre[i][1];
            int v=pre[i][0];
            g[u].push_back(v);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> visdfs(vis);
        for(int i=0;i<numCourses;i++){
            if(dfs(g,vis,visdfs,i)){
                return false;
            }
        }
        return true;
    }
};