class Solution {
public:
    bool dfs(vector<vector<int>> &g,vector<bool> &vis,vector<bool> &dfsvis,int node){
        vis[node]=true;
        dfsvis[node]=true;
        for(int i=0;i<g[node].size();i++){
            if(!vis[g[node][i]]){
                if(dfs(g,vis,dfsvis,g[node][i])){
                    return true;
                }
            }
            else if(dfsvis[g[node][i]]){
                return true;
            }
        }
        dfsvis[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            g[v].push_back(u);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> dfsvis(g.size(),false);
        for(int i=0;i<g.size();i++){
            if(!vis[i]){
                if(dfs(g,vis,dfsvis,i)){
                    return false;
                }
            }
        }
        return true;
    }
};