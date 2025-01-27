class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            g[u].push_back({v,w});
        }
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,src}});
        vector<int> ans(n,INT_MAX);
        while(!q.empty()){
            int stops=q.top().first;
            int cost=q.top().second.first;
            int node=q.top().second.second;
            q.pop();
            if(stops>k){
                continue;
            }
            for(int i=0;i<g[node].size();i++){
                auto temp=g[node][i];
                int c=temp.second;
                int no=temp.first;
                if(cost+c<ans[no]){
                    ans[no]=cost+c;
                    q.push({stops+1,{ans[no],no}});
                }
            }
        }
        if(ans[dst]==INT_MAX)
        return -1;
        return ans[dst];

    }
};