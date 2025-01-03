class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long,long long> ,vector<pair<long long,long long>> ,greater<pair<long long,long long>>> pq;
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
            g[u].push_back({v,wt});
            g[v].push_back({u,wt});
        }
        vector<long long> ans(n,1e12), ways(n,0);
        pq.push({0,0});
        ans[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            auto temp=pq.top();
            long long wt=temp.first;
            long long node=temp.second;
            pq.pop();
            for(int i=0;i<g[node].size();i++){
                auto temp2=g[node][i];
                long long w=temp2.second;
                long long no=temp2.first;
                if(ans[no]>w+wt){
                    ans[no]=w+wt;
                    pq.push({ans[no],no});
                    ways[no]=ways[node];
                }
                else if(ans[no]==w+wt){
                    ways[no]=(ways[no]+ways[node])%MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};