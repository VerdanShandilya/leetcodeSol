class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int row=matrix.size();
        int col=matrix[0].size();
        int lwall=-1;
        int rwall=col;
        int uwall=0;
        int dwall=row;
        int i=0,j=0;
        char dir='r';
        while(v.size()!=col*row){
            v.push_back(matrix[i][j]);
            if(dir=='r'){
                j++;
                if(j==rwall){
                    rwall--;
                    j--;
                    dir='d';
                    i++;
                }
            }
            else if(dir=='d'){
                i++;
                if(i==dwall){
                    dwall--;
                    i--;
                    dir='l';
                    j--;
                }
            }
            else if(dir=='l'){
                j--;
                if(j==lwall){
                    lwall++;
                    j++;
                    dir='u';
                    i--;
                }
            }
            else if(dir=='u'){
                i--;
                if(i==uwall){
                    uwall++;
                    i++;
                    dir='r';
                    j++;
                }
            }
        }
        return v;
    }
};