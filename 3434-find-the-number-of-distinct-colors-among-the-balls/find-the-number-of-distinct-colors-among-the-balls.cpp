class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m;

        int count=0;
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            if(m1.find(u)!=m1.end()){
                m[m1[u]]--;
                if(m[m1[u]]==0){
                    m.erase(m1[u]);
                }
                m1.erase(u);
            }
            m1[u]=v;
            m[v]++;
            ans.push_back(m.size());
        }
        return ans;
    }
};