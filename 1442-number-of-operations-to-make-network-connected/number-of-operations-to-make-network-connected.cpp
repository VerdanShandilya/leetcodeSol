class Solution {
public:

    int findp(vector<int> &par,int u){
        if(par[u]==u){
            return u;
        }
        return par[u]=findp(par,par[u]);
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

    int makeConnected(int n, vector<vector<int>>& con) {
        int cables=con.size();
        if(cables<n-1) return -1;

        vector<int> size(n,1);
        vector<int> par(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(int i=0;i<con.size();i++){
            int u=con[i][0];
            int v=con[i][1];
            unionset(par,size,u,v);
        }
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(findp(par,i));
        }
        int req=s.size();
        return req-1;

    }
};