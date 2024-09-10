class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> count(edges.size()+2,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            count[u]++;
            count[v]++;
        }
        for(int i=1;i<count.size();i++){
            if(count[i]==edges.size()){
                return i;
            }
        }
        return -1;
    }
};