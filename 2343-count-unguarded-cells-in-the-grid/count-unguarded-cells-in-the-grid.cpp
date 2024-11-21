class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> v(m,vector<int> (n,-1));
        for(int i=0;i<guards.size();i++){
            int u=guards[i][0];
            int a=guards[i][1];
            v[u][a]=1;
        }
        for(int i=0;i<walls.size();i++){
            int u=walls[i][0];
            int a=walls[i][1];
            v[u][a]=1;
        }
        for(int i=0;i<guards.size();i++){
            int u=guards[i][0];
            int a=guards[i][1];
            for(int j=u+1;j<v.size();j++){
                if(v[j][a]==1)
                break;
                v[j][a]=2;
            }
            for(int j=u-1;j>=0;j--){
                if(v[j][a]==1)
                break;
                v[j][a]=2;
            }
            for(int j=a+1;j<v[0].size();j++){
                if(v[u][j]==1)
                break;
                v[u][j]=2;
            }
            for(int j=a-1;j>=0;j--){
                if(v[u][j]==1)
                break;
                v[u][j]=2;
            }
        }
        int ans=0;
        for(int i =0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]==-1){
                    ans++;
                }
            }
        }
        return ans;
    }
};