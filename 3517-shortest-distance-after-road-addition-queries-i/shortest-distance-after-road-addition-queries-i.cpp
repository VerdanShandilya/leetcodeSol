class Solution {
public:
    int bfs(vector<vector<int>> &g,vector<bool> visited,vector<int> parent){
        queue<int> q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(int i=0;i<g[temp].size();i++){
                if(visited[g[temp][i]]==false){
                    q.push(g[temp][i]);
                    visited[g[temp][i]]=true;
                    parent[g[temp][i]]=temp;
                }
            }
        }
        int ans=0;
        int curr=g.size()-1;
        while(curr!=0){
            curr=parent[curr];
            ans++;
        }
        return ans;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<int>> g(n);
        for(int i=0;i<n-1;i++){
            g[i].push_back(i+1);
        }
        vector<bool> visited(g.size(),false);
        vector<int> parent(g.size(),-1);
        for(int i=0;i<queries.size();i++){
            g[queries[i][0]].push_back(queries[i][1]);
            ans.push_back(bfs(g,visited,parent));
        }
        return ans;
    }
};