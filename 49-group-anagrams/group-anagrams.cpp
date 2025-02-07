class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            m[temp].push_back(strs[i]);
        }
        for(auto i : m){
            auto temp=i.second;
            vector<string> v;
            for(int j=0;j<temp.size();j++){
                v.push_back(temp[j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};