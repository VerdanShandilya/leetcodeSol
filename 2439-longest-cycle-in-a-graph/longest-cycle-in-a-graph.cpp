class Solution {
public:
int res=-1;
    void dfs(vector<bool> &vis,vector<int>& edges,vector<int> &depth,int ans,int node){
        vis[node]=true;
        depth[node]=ans;
        ans++;
        if(edges[node]!=-1){
            if(!vis[edges[node]]){
                dfs(vis,edges,depth,ans,edges[node]);
            }
            else if(depth[edges[node]]!=INT_MIN){
                int len=ans-depth[edges[node]];
                res=max(len,res);
            }
        }
        depth[node]=INT_MIN;
        return;
    }
    int longestCycle(vector<int>& edges) {
        vector<bool> vis(edges.size(),false);
        vector<int> depth(edges.size(),INT_MIN);
        for(int i=0;i<edges.size();i++){
            if(!vis[i]){
                dfs(vis,edges,depth,0,i);
            }
        }
        return res;
    }
};