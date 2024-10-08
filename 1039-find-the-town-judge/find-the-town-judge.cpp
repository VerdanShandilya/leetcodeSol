class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustc(n+1,0);
        vector<int> trustb(n+1,0);
        for(int i=0;i<trust.size();i++){
            int u=trust[i][0];
            int v=trust[i][1];
            trustc[u]++;
            trustb[v]++;
        }
        for(int i=1;i<trustc.size();i++){
            if(trustb[i]==n-1 && trustc[i]==0){
                return i;
            }
        }
        return -1;
    }
};