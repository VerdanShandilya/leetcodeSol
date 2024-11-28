class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            int count=0;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    count++;
                }
                if(count>1){
                    break;
                }
            }
            if(count==1){
                return i;
            }
        }
        return 0;
    }
};