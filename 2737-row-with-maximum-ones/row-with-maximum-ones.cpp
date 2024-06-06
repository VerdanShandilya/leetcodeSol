// class Solution {
// public:
//     vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
//         int max=0;
//         int index=0;
//         for(int i=0;i<mat.size();i++){
//             int count=0;
//             for(int j=0;j<mat[i].size();j++){
//                 if(mat[i][j]==1){
//                     count++;
                    
//                 }
//             }
//             if(count>max){
//                 max=count;
//                 index=i;
//             }
//         }
//         return {index,max};
//     }
// };



class Solution {
public:

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int maxcount=-1;
        int index=-1;
        vector<int>v;
        for(int i =0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                count =count+mat[i][j];
            }
            if(count>maxcount){
                maxcount=count;
                index=i;   
            }
        }
        v.push_back(index);
        v.push_back(maxcount);
        return v;
        
    }
};