class Solution {
public:
    const int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long> ans(n,1e12),ways(n,0);
        vector<vector<pair<long,long>>> g(n);
        for(auto i : roads){
            g[i[0]].push_back({i[1],i[2]});
            g[i[1]].push_back({i[0],i[2]});
        }
        ans[0]=0;
        ways[0]=1;
        priority_queue<pair<long,long>, vector<pair<long,long>>, greater<pair<long,long>>> q;
        q.push({0,0});
        while(!q.empty()){
            long w=q.top().first;
            long node=q.top().second;
            q.pop();
            for(auto i : g[node]){
                if(w+i.second<ans[i.first]){
                    ans[i.first]=w+i.second;
                    q.push({ans[i.first],i.first});
                    ways[i.first]=ways[node];
                }
                else if(w+i.second==ans[i.first]){
                    ways[i.first]=(ways[node]+ways[i.first])%MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};