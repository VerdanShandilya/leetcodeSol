class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        vector<int> vis(rooms.size(),false);
        vis[0]=true;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int i=0;i<rooms[temp].size();i++){
                if(!vis[rooms[temp][i]]){
                    q.push(rooms[temp][i]);
                    vis[rooms[temp][i]]=true;
                }
            }
        }
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};