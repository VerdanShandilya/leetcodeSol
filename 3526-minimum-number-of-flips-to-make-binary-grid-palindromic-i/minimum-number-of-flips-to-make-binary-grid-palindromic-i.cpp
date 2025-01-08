class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            int l=0;
            int r=grid[0].size()-1;
            while(l<=r){
                if(grid[i][l]!=grid[i][r]){
                    ans++;
                }
                l++;
                r--;
            }
        }
        int sum=0;
        for(int i=0;i<grid[0].size();i++){
            int l=0;
            int r=grid.size()-1;
            while(l<=r){
                if(grid[l][i]!=grid[r][i]){
                    sum++;
                }
                l++;
                r--;
            }
        }
        return min(ans,sum);
    }
};