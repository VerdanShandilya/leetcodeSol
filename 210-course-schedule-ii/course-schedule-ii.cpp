class Solution {
public:
    bool dfs(vector<vector<int>>& g,vector<bool> &vis,vector<bool> &dfsvis,int node,stack<int> &s){
        vis[node]=true;
        dfsvis[node]=true;
        for(int i=0;i<g[node].size();i++){
            if(!vis[g[node][i]]){
                if(dfs(g,vis,dfsvis,g[node][i],s)){
                    return true;
                }
            }
            else if(dfsvis[g[node][i]]){
                return true;
            }
        }
        dfsvis[node]=false;
        s.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            g[v].push_back(u);
        }
        vector<bool> dfsvis(g.size(),false);
        vector<bool> vis(g.size(),false);
        stack<int> s;
        for(int i=0;i<g.size();i++){
            if(!vis[i]){
                if(dfs(g,vis,dfsvis,i,s)){
                    return {};
                }
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};