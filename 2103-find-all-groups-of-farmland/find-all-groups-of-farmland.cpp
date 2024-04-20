class Solution {
public:
    void erase(vector<vector<int>>& land,int i,int j, int& c1,int& c2){
        int n=land.size();
        int m=land[0].size();
        if(i<0 || i==n || j<0 || j==m || land[i][j]==0){
            return ;
        }
        c1=max(i,c1);
        c2=max(j,c2);
        land[i][j]=0;
        erase(land,i+1,j,c1,c2);
        erase(land,i-1,j,c1,c2);
        erase(land,i,j+1,c1,c2);
        erase(land,i,j-1,c1,c2);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> v;
        int n=land.size();
        int m=land[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    int c1=i;
                    int c2=j;
                    vector<int> v1;
                    v1.push_back(i);
                    v1.push_back(j);
                    erase(land,i,j,c1,c2);
                    v1.push_back(c1);
                    v1.push_back(c2);
                    v.push_back(v1);
                }
            }
        }
        return v;
    }
};