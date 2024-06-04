// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());
//         if(s.size()!=t.size()){
//             return false;
//         }
//         for(int i=0;i<min(s.size(),t.size());i++){
//             if(s[i]!=t[i]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        for(auto i : s){
            m[i]++;
        }
        for(auto i : t){
            m[i]--;
        }
        for(auto i: m){
            if(i.second!=0){
                return false;
            }
        }
        return true;
    }
};