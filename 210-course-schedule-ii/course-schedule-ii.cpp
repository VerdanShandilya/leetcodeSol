class Solution {
public:
    bool dfs(vector<bool> &vis,vector<bool> &visdfs,vector<vector<int>> &g,int node,stack<int> &s){
        vis[node]=true;
        visdfs[node]=true;
        for(int i=0;i<g[node].size();i++){
            if(!vis[g[node][i]]){
                if(dfs(vis,visdfs,g,g[node][i],s)){
                    return true;
                }
            }
            else if(visdfs[g[node][i]]){
                return true;     
            }
        }
        visdfs[node]=false;
        s.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> g(numCourses);
        for(int i=0;i<pre.size();i++){
            int u=pre[i][1];
            int v=pre[i][0];
            g[u].push_back(v);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> visdfs(numCourses,false);
        stack<int> s;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(vis,visdfs,g,i,s)){
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