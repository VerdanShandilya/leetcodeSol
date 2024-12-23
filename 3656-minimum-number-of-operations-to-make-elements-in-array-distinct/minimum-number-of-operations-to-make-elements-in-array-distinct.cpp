class Solution {
public:
    int minimumOperations(vector<int>& v) {
        unordered_map<int,int> m;
        for(auto i : v){
            m[i]++;
        }
        int ans=0;
        while(v.size()>0){
            int dup=0;
            for(auto i : m){
                if(i.second>1){
                    dup++;
                    break;
                }
            }
            if(dup==1){
                dup=0;
                ans++;
                if(v.size()>=3){
                    m[v[0]]--;
                    m[v[1]]--;
                    m[v[2]]--;
                    v.erase(v.begin()+0,v.begin()+3);
                }
                else{
                    while(v.size()>0){
                        m[v[0]]--;
                        v.erase(v.begin());
                    }
                }
            }
            else{
                break;
            }
        }
        return ans;
    }
};