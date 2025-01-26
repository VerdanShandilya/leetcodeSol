class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> g(numCourses);
        for(int i=0;i<pre.size();i++){
            int u=pre[i][1];
            int v=pre[i][0];
            g[u].push_back(v);
        }
        vector<int> ind(numCourses,0);
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[i].size();j++){
                ind[g[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<ind.size();i++){
            if(!ind[i]){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            auto temp= q.front();
            q.pop();
            ans.push_back(temp);
            for(int i=0;i<g[temp].size();i++){
                ind[g[temp][i]]--;
                if(ind[g[temp][i]]==0){
                    q.push(g[temp][i]);
                }
            }
        }
        if(ans.size()==numCourses){
            return ans;
        }
        return {};
    }
};