class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n);
        for(int i=0;i<invocations.size();i++){
            int u=invocations[i][0];;
            int v=invocations[i][1];
            g[u].push_back(v);
        }
        vector<bool> visited(n,false);
        vector<bool> sus(n,false);
        sus[k]=true;
        queue<int> q;
        visited[k]=true;
        q.push(k);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(int i=0;i<g[temp].size();i++){
                if(!visited[g[temp][i]]){
                    visited[g[temp][i]]=true;
                    sus[g[temp][i]]=true;
                    q.push(g[temp][i]);
                }
            }
        }
        vector<bool> sus1;
        sus1=sus;
        bool a=false;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[i].size();j++){
                if(sus[i]==true){
                    break;
                }
                if(sus[g[i][j]]==true){
                    sus1[g[i][j]]=false;
                    a=true;
                }
            }
        }
        vector<int> ans;
        if(a==false){
            for(int i=0;i<sus1.size();i++){
                if(sus1[i]==false){
                    ans.push_back(i);
                }
            }
        }
        else{
            for(int i=0;i<sus1.size();i++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};