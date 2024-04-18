class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    if((i>0 && grid[i-1][j]!=1) || i==0){
                        count+=1;
                    }
                    if((j>0 && grid[i][j-1]!=1 )|| j==0){
                        count+=1;
                    }
                    if((j<grid[0].size()-1 && grid[i][j+1]!=1) || j==grid[0].size()-1  ){
                        count+=1;
                    }
                    if((i<grid.size()-1 && grid[i+1][j]!=1) || i==grid.size()-1){
                        count+=1;
                    }
                }
            }
        }
        return count;
    }
};