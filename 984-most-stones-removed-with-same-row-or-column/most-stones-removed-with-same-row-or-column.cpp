class Solution {
public:
    int findp(vector<int> &par,int u){
        if(par[u]==u){
            return u;
        }
        par[u]=findp(par,par[u]);
        return par[u];
    }

    void unionset(vector<int> &par,vector<int> &size,int u,int v){
        int pu=findp(par,u);
        int pv=findp(par,v);
        
        if(pu==pv){
            return;
        }
        if(size[pu]>size[pv]){
            par[pv]=par[pu];
            size[pu]+=size[pv];
        }
        else{
            par[pu]=par[pv];
            size[pv]+=size[pu];
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int rows = 0, cols = 0;
        for(auto vec : stones){
            rows = max(rows, vec[0]);
            cols = max(cols, vec[1]);
        }

        int total = rows + cols + 2;

        vector<int> par(total);
        vector<int> size(total,1);
        for(int i=0;i<total;i++){
            par[i]=i;
        }

        for(int i=0;i<stones.size();i++){
            unionset(par,size,stones[i][0], rows+1+stones[i][1]);
        }
        set<int> s;
        for(auto &stone : stones){
            s.insert(findp(par, stone[0]));
        }
        return stones.size() - s.size();
    }
};