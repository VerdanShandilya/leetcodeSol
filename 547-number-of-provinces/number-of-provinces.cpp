class Solution {
public:
    void bfs(vector<vector<int>>& adj,vector<bool> &v,int i){
        queue<int> q;
        q.push(i);
        v[i]=true;
        while(!q.empty()){
            int ans=q.front();
            q.pop();
            for(auto j : adj[ans]){
                if(v[j]!=true){
                    q.push(j);
                    v[j]=true;
                }
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<bool> v(isConnected.size(),false);
        for(int i=0;i<isConnected.size();i++){
            if(v[i]==false){
                ans++;
                bfs(adj,v,i);
            }
        }
        return ans;
    }
};