class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        unordered_map<string,int> m;
        int k1=s.size()/k;
        int i=0;
        while(i<s.size()){
            m[s.substr(i,k1)]++;
            i=i+k1;
        }
        i=0;
        while(i<t.size()){
            m[t.substr(i,k1)]--;
            i=i+k1;
        }
        for(auto i : m){
            if(i.second!=0){
                return false;
            }
        }
        return true;
    }
};