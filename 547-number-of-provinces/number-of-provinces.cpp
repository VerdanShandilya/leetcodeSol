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


    int findCircleNum(vector<vector<int>>& isc) {
        vector<int> size(isc.size(),1);
        vector<int> par(isc.size());
        for(int i=0;i<isc.size();i++){
            par[i]=i;
        }
        for(int i=0;i<isc.size();i++){
            for(int j=0;j<isc[0].size();j++){
                if(isc[i][j]==1){
                    unionset(par,size,i,j);
                }
            }
        }
        set<int> s;
        for(int i=0;i<par.size();i++){
            s.insert(findp(par,i));
        }
        return s.size();
    }
};