class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,stack<int>> m;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            m[temp].push(i);
        }
        for(auto i : m){
            auto temp=i.second;
            vector<string> v;
            while(!temp.empty()){
                v.push_back(strs[temp.top()]);
                temp.pop();
            }
            ans.push_back(v);
        }
        return ans;
    }
};