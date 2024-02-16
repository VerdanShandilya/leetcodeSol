class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> p;
        for(int i=lo;i<=hi;i++){
            int count=0;
            int copy=i;
            while(copy!=1){
                if(copy%2==0){
                    copy=copy/2;
                    count++;
                }
                else{
                    copy=(copy*3)+1;
                    count++;
                }
            }
            p.push_back({count,i});
        }
        sort(p.begin(),p.end());
        return p[k-1].second;
    }
};