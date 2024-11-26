class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> v(n,-1);
        for(int i=0;i<edges.size();i++){
            v[edges[i][1]]=1;
        }
        int count=0;
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==-1){
                count++;
                ans=i;
            }
        }
        if(count>1)
        return -1;
        return ans;
    }
};