class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max=0;
        int index=0;
        for(int i=0;i<mat.size();i++){
            int count=0;
            for(int j=0;j<mat[i].size();j++){
                sort(mat[i].begin(),mat[i].end());
                if(mat[i][j]==1){
                    count=mat[i].size()-j;
                    break;
                }
            }
            if(count>max){
                max=count;
                index=i;
            }
        }
        return {index,max};
    }
};