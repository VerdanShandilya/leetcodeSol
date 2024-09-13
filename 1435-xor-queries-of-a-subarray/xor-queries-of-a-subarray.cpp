class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0];
            int b=queries[i][1];
            int x=0;
            for(int j=a;j<=b;j++){
                x=x^arr[j];
            }
            ans.push_back(x);
        }
        return ans;
    }
};