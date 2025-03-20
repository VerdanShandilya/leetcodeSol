class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows==1){
            return {{1}};
        }
        if(numRows==2){
            return {{1},{1,1}};
        }
        ans.push_back({1});
        ans.push_back({1,1});
        vector<int> v;
        for(int i=2;i<numRows;i++){
            v.push_back(1);
            for(int j=1;j<ans[i-1].size();j++){
                v.push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
            v.push_back(1);
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};