class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> v;
        vector<vector<int>> h;
        for(int i=0;i<rectangles.size();i++){
            v.push_back({rectangles[i][0],rectangles[i][2]});
            h.push_back({rectangles[i][1],rectangles[i][3]});
        }
        sort(v.begin(),v.end());
        sort(h.begin(),h.end());
        int k=0;
        for(int i=1;i<v.size();i++){
            if(v[k][1]>v[i][0]){
                v[k][1]=max(v[k][1],v[i][1]);
            }
            else{
                k++;
                v[k]=v[i];
            }
        }
        v.resize(k+1);
        k=0;
        for(int i=1;i<h.size();i++){
            if(h[k][1]>h[i][0]){
                h[k][1]=max(h[k][1],h[i][1]);
            }
            else{
                k++;
                h[k]=h[i];
            }
        }
        h.resize(k+1);
        if(h.size()<3 && v.size()<3){
            return false;
        }
        int cnt=0;
        for(int i=1;i<v.size();i++){
            if(v[i][0]==v[i-1][1]){
                cnt++;
            }
        }
        if(cnt>=2){
            return true;
        }
        cnt=0;
        for(int i=1;i<h.size();i++){
            if(h[i][0]==h[i-1][1]){
                cnt++;
            }
        }
        if(cnt>=2){
            return true;
        }
        return false;
    }
};