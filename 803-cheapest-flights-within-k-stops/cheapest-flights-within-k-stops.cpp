class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int cost=flights[i][2];
            g[u].push_back({v,cost});
        }
        queue<pair<int, pair<int, int>>> pq;
        vector<int> ans(n,INT_MAX);
        pq.push({0,{src,0}});
        ans[src]=0;
        while(!pq.empty()){
            auto temp=pq.front();
            int cost=temp.second.second;
            int nk=temp.first;
            int node=temp.second.first;
            pq.pop();
            if (nk > k) continue;
            for(int i=0;i<g[node].size();i++){
                auto temp2=g[node][i];
                int c=temp2.second;
                int n=temp2.first;
                
                if(ans[n]>c+cost){
                    ans[n]=c+cost;
                    pq.push({nk+1,{n,ans[n]}});
                }
            }
        }
        if(ans[dst]==INT_MAX){
            return -1;
        }
        return ans[dst];
    }
};


