class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> g(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            g[u].push_back({v,w});
        }
        vector<int> ans(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> q;
        q.push({0,k});
        ans[k]=0;
        while(!q.empty()){
            int time=q.top().first;
            int node=q.top().second;
            q.pop();
            for(int i=0;i<g[node].size();i++){
                auto temp=g[node][i];
                int t=temp.second;
                int no=temp.first;
                if(ans[no]==INT_MAX || t+time<ans[no]){
                    ans[no]=t+time;
                    q.push({ans[no],no});
                }
            }
        }
        int res=0;
        for(int i=1;i<ans.size();i++){
            if(ans[i]==INT_MAX){
                return -1;
            }
            res=max(res,ans[i]);
        }
        return res;
    }
};