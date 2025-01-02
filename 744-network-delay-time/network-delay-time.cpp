class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<times.size();i++){
            int u=times[i][0]-1;
            int v=times[i][1]-1;
            int wt=times[i][2];
            g[u].push_back({v,wt});
        }
        pq.push({0,k-1});
        vector<int> ans(n,INT_MAX);
        ans[k-1]=0;
        while(!pq.empty()){
            auto temp=pq.top();
            int wt=temp.first;
            int node=temp.second;
            pq.pop();
            for(int i=0;i<g[node].size();i++){
                auto temp2=g[node][i];
                int w=temp2.second;
                int n=temp2.first;
                if(ans[n]>ans[node]+w){
                    ans[n]=ans[node]+w;
                    pq.push({ans[n],n});
                }
            }
        }
        int res=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==INT_MAX){
                return -1;
            }
            res=max(res,ans[i]);
        }
        return res;
    }
};