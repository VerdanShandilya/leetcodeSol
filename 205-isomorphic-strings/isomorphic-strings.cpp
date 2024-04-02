class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // for(int i=0;i<s.length();i++){
        //     for(int j=i+1;j<s.length();j++){
        //         if(s[j]==s[i] && t[j]!=t[i]){
        //             return false;
        //         }
        //         if(s[j]!=s[i] && t[j]==t[i]){
        //             return false;
        //         }
        //     }
        // }
        // return true;
        vector<pair<char,char>> v;
        for(int i=0;i<s.length();i++){
            auto it =find_if(v.begin(),v.end(), [&](const auto& pair) {
            return pair.first ==s[i];
            });
            auto itt =find_if(v.begin(),v.end(), [&](const auto& pair) {
            return pair.second ==t[i];
            });
            if(it!=v.end()){
                if(it->second!=t[i]){
                 return false;
                }
            }
            if(itt!=v.end()){
                if(itt->first!=s[i]){
                 return false;
                }
            }
            else{
                v.push_back(make_pair(s[i], t[i]));
            }
        }
        return true;
    }
};