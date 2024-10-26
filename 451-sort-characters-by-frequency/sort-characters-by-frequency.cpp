class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        vector<pair<int,char>> v;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        for(auto i : m){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end(),greater<pair<int,char>>());
        string ans = "";
        for (auto &p : v) {
            ans += string(p.first, p.second);
        }
        return ans;
    }
};