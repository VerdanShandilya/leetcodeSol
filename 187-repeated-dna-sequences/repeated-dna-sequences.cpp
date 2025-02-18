class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10){
            return {};
        }
        unordered_map<string,int> m;
        int len=10;
        int l=0;
        int r=0;
        while(r<s.size()){
            if(r-l+1==len){
                string temp=s.substr(l,r-l+1);
                m[temp]++;
                l++;
            }
            r++;
        }
        vector<string> ans;
        for(auto i : m){
            if(i.second>1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};