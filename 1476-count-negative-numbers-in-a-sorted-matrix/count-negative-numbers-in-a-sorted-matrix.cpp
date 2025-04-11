class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int j=0;
        int i=grid.size()-1;
        int ans=0;
        while(i>-1 && j>-1 && i<grid.size() && j<grid[0].size()){
            if(grid[i][j]>=0){
                j++;
            }
            else if(grid[i][j]<0){
                ans+=grid[i].size()-j;
                i--;
            }
        }
        return ans;
    }
};