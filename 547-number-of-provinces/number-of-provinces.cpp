class Solution {
public:
    void bfs(vector<vector<int>> &adj,vector<bool> &visit,int a){
        queue<int> q;
        q.push(a);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(int i=0;i<adj[temp].size();i++){
                if(visit[adj[temp][i]]!=true){
                    visit[adj[temp][i]]=true;
                    q.push(adj[temp][i]);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> visit(n,false);
        int count=0;
        for(int i=0;i<visit.size();i++){
            if(visit[i]!=true){
                count++;
                bfs(adj,visit,i);
            }
        }
        return count;
    }
};